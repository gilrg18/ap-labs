package main

import (
	"fmt"
	"os"
	"path/filepath"
)

// scanDir stands for the directory scanning implementation
func scanDir(root string) error {

	dirs := 0
	files := 0
	var ff = func(pathX string, infoX os.FileInfo, errX error) error {

		if errX != nil {
			return errX
		}

		if infoX.IsDir() {
			dirs++
		} else {
			files++
		}

		return nil
	}

	err := filepath.Walk(root, ff)

	fmt.Printf("\n\n%s\n", root)
	fmt.Println("--------------------------")
	fmt.Printf("Directories %d\n", dirs)
	fmt.Println("--------------------------")
	fmt.Printf("Files %d", files)

	if err != nil {
		return fmt.Errorf("error walking the path %s: %v\n", root, err)
	}

	return nil
}

func main() {

	if len(os.Args) < 2 {
		fmt.Println("Usage: ./dir-scan <directory>")
		os.Exit(1)
	}

	scanDir(os.Args[1])
}