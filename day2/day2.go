package day2

import (
	"log"
	"strconv"
	"strings"
)

const (
	redLim   = 12
	greenLim = 13
	blueLim  = 14
)

var limits = map[string]int64{
	"red":   12,
	"green": 13,
	"blue":  14,
}

func Day2p1(s *string) {
	var res int64 = 0
	games := strings.Split(*s, "\n")
	isOk := true

	for _, game := range games {
		isOk = true
		gameIdAndRes := strings.Split(game, ":")
		if len(gameIdAndRes) != 2 {
			break
		}
		gameId := gameIdAndRes[0][5:]

		gameRes := strings.Split(gameIdAndRes[1][1:], "; ")

		for _, round := range gameRes {
			colors := strings.Split(round, ", ")

			for _, cubes := range colors {
				cube := strings.Split(cubes, " ")
				cubeCount := cube[0]
				cubeColor := cube[1]
				int, _ := strconv.ParseInt(cubeCount, 10, 64)
				limit, _ := limits[cubeColor]
				if int > limit {
					isOk = false
				}
			}
		}

		if isOk {
			gameIdInt, _ := strconv.ParseInt(gameId, 10, 64)
			res += gameIdInt
		}
	}
	log.Printf("day 2 p1 answer: '%v'", res)
}
