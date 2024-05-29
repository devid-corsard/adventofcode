package day1

import (
	"fmt"
	"strconv"
	"strings"
)

func Day1p1(s string) int {
	lines := strings.Split(s, "\n")
	var res = 0

	for _, line := range lines {
		var firstDigit, lastDigit string
		var isFirstDigit = false

		letters := strings.Split(line, "")

		for _, letter := range letters {
			if _, err := strconv.ParseInt(letter, 10, 8); err == nil {
				if !isFirstDigit {
					firstDigit = letter
					isFirstDigit = true
				}

				lastDigit = letter
			}
		}
		lineNumber, _ := strconv.ParseInt(firstDigit+lastDigit, 10, 8)
		res += int(lineNumber)
	}
	fmt.Println(res)
	return res
}

func Day1p2(s string) int {
	lines := strings.Split(s, "\n")
	numbersAsWords := []string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	var res = 0

	for _, line := range lines {
		var firstDigit, lastDigit string
		var isFirstDigit = false

		for idx, letter := range strings.Split(line, "") {
			for digit, wordNum := range numbersAsWords {
				if len(line) >= idx+len(wordNum) && line[idx:idx+len(wordNum)] == wordNum {
					if !isFirstDigit {
						firstDigit = strconv.Itoa(digit)
						isFirstDigit = true
					}

					lastDigit = strconv.Itoa(digit)

				}
			}

			if _, err := strconv.ParseInt(letter, 10, 8); err == nil {
				if !isFirstDigit {
					firstDigit = letter
					isFirstDigit = true
				}

				lastDigit = letter
			}

		}

		lineNumber, _ := strconv.ParseInt(firstDigit+lastDigit, 10, 8)
		res += int(lineNumber)
	}
	fmt.Println("day1 p1 answer: ", res)
	return res
}
