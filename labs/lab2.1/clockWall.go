package main

import (
    "fmt"
    "log"
    "net"
    "io/ioutil"
    "os"
    "strings"
)


func main() {
    fmt.Println("start client");
    
    for i := 1; i < len(os.Args); i++ {
        words := strings.Split(os.Args[i], "=")

        conn, erro := net.Dial("tcp", words[1])
        if erro != nil {
            log.Print(erro)
        }

        bs, err := ioutil.ReadAll(conn)
        if err != nil {
            log.Print(err)
            return
        }
        fmt.Println(words[0]+ " : " + string(bs))
    }
}