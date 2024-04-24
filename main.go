package main

import (
	"devid-corsard/aoc2023/day1"
	"io"
	"os"
)

const day1p1Input = `1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet`

func main() {
	day1.Day1p1(day1p1Input)

	file, _ := os.Open("./day1/day1p1.txt")
	b, _ := io.ReadAll(file)
	day1.Day1p1(string(b))
}
