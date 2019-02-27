// Clock2 is a concurrent TCP server that periodically writes the time.
package main

import (
	"io"
	"log"
	"net"
	"time"
	"os"
	"fmt"
)

func TimeIn(t time.Time, name string) (time.Time, error) {
    loc, err := time.LoadLocation(name)
    if err == nil {
        t = t.In(loc)
    }
    return t, err
}

func handleConn(c net.Conn, timeZone string) {
	defer c.Close()

	t, erro := TimeIn(time.Now(), timeZone)
	if erro != nil {
		return
	}

	_, err := io.WriteString(c, t.Format("15:04:05"))
	if err != nil {
		return // e.g., client disconnected
	}

	time.Sleep(1 * time.Second)
		
}

func main() {
	fmt.Println("Listening...")

	if len(os.Args) < 3 {
		log.Print("Incorrect number of arguments")
		os.Exit(1)
	}

	listener, err := net.Listen("tcp", "localhost:" + os.Args[1])
	if err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err) // e.g., connection aborted
			continue
		}
			go handleConn(conn, os.Args[2]) // handle connections concurrently
	}
}