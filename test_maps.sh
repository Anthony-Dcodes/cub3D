# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_maps.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/12 11:57:52 by msnizek           #+#    #+#              #
#    Updated: 2026/07/19 14:22:35 by msnizek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

CUB3D="./cub3D"
INVALID_DIR="maps/invalid_maps"
VALID_DIR="maps/valid_maps"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
GRAY='\033[0;90m'
NC='\033[0m'

if [ ! -f "$CUB3D" ]; then
	echo -e "${RED}Error: File $CUB3D does not exist.${NC}"
	exit 1
fi

echo -e "${CYAN}=========================================${NC}"
echo -e "${CYAN}          TESTS OF INVALID MAPS          ${NC}"
echo -e "${CYAN}=========================================${NC}"

for map in "$INVALID_DIR"/*.cub; do
	[ -e "$map" ] || continue 

	map_name=$(basename "$map")
	output=$(timeout 2 "$CUB3D" "$map" 2>&1)
	exit_code=$?

	if [ $exit_code -eq 124 ]; then
		echo -e "${RED}[KO]${NC} $map_name -> Program is running. Map went through the parser."
	elif [ $exit_code -ne 0 ]; then
		if echo "$output" | grep -q "^Error"; then
			echo -e "${GREEN}[OK]${NC} $map_name -> Dissmissed correctly."
			echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
		else
			echo -e "${YELLOW}[??]${NC} $map_name -> Dissmissed, but without 'Error' message."
			echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
		fi
	else
	echo -e "${RED}[KO]${NC} $map_name -> Successfully completed(Exit kód 0), it is wrong."
	fi
done

echo ""
echo -e "${CYAN}=========================================${NC}"
echo -e "${CYAN}            TESTS OF VALID MAPS          ${NC}"
echo -e "${CYAN}=========================================${NC}"

for map in "$VALID_DIR"/*.cub; do
	[ -e "$map" ] || continue

	map_name=$(basename "$map")
	output=$(timeout 2 "$CUB3D" "$map" 2>&1)
	exit_code=$?

	if [ $exit_code -eq 124 ]; then
		echo -e "${GREEN}[OK]${NC} $map_name -> Map is loading correctly and the game is running (end with timeout)."
	elif [ $exit_code -eq 0 ]; then
		echo -e "${YELLOW}[??]${NC} $map_name -> Terminated immediately."
	else
		echo -e "${RED}[KO]${NC} $map_name -> Program crashed (Exit kód $exit_code)!"
		echo -e "${YELLOW}     Výpis:${NC}"
		echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
	fi
done

echo -e "\n${CYAN}=========================================${NC}"
echo -e "${YELLOW}               HOTOVO!                   ${NC}"
echo -e "${CYAN}=========================================${NC}"