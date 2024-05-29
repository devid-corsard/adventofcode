package main

import (
	"devid-corsard/aoc2023/day1"
	"devid-corsard/aoc2023/day2"
	"io"
	"os"
)

func main() {
	const day1p1Input = `1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet`
	day1.Day1p1(day1p1Input)

	file, _ := os.Open("./day1/day1p1.txt")
	b, _ := io.ReadAll(file)
	day1.Day1p1(string(b))

	const day1p2Inp = `two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen`
	day1.Day1p2(day1p2Inp)

	file, _ = os.Open("./day1/day1p2.txt")
	b, _ = io.ReadAll(file)
	day1.Day1p2(string(b))

	var day2p1Example = `Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green`
	day2.Day2p1(&day2p1Example)

	file, _ = os.Open("./day2/day2p1.txt")
	b, _ = io.ReadAll(file)
	var d2p1 = string(b)
	day2.Day2p1(&d2p1)
}
