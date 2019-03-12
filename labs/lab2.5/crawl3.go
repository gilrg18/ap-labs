// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 241.

// Crawl2 crawls web links starting with the command-line arguments.
//
// This version uses a buffered channel as a counting semaphore
// to limit the number of concurrent calls to links.Extract.
package main

import (
	"flag"
	"fmt"
	"log"

	"gopl.io/ch5/links"
)

var maxdepth int
var args []string

type Work struct {
	url   string
	depth int
}

func init() {
	flag.IntVar(&maxdepth, "depth", 1, "max depth to crawl")
	flag.Parse()
	args = flag.Args()
}

//!+sema
// tokens is a counting semaphore used to
// enforce a limit of 20 concurrent requests.
var tokens = make(chan struct{}, 20)

func crawl(work Work) []Work {
	fmt.Printf("%d\t%s\n", work.depth, work.url)

	if work.depth >= maxdepth {
		return nil
	}

	tokens <- struct{}{} // acquire a token
	list, err := links.Extract(work.url)
	<-tokens // release the token

	if err != nil {
		log.Print(err)
	}

	works := []Work{}
	for _, link := range list {
		works = append(works, Work{link, work.depth + 1})
	}
	return works
}

//!-sema

//!+
func main() {
	worklist := make(chan []Work)
	var n int // number of pending sends to worklist

	// Start with the command-line arguments.
	n++
	go func() {
		works := []Work{}
		for _, url := range args {
			works = append(works, Work{url, 1})
		}
		worklist <- works
	}()

	// Crawl the web concurrently.
	seen := make(map[string]bool)
	for ; n > 0; n-- {
		list := <-worklist
		for _, link := range list {
			if !seen[link.url] {
				seen[link.url] = true
				n++
				go func(link Work) {
					worklist <- crawl(link)
				}(link)
			}
		}
	}
}

//!-
