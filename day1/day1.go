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
