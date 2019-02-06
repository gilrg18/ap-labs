package main

import (
	"strings"

	"golang.org/x/tour/wc"
)

var myMap map[string]int
var word string

func WordCount(s string) map[string]int {
	myMap = make(map[string]int)

	for _, word := range strings.Fields(s) {
		myMap[word] += 1
	}
	return myMap
}

func main() {
	wc.Test(WordCount)
}
