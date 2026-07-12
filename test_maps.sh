# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_maps.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/12 11:57:52 by msnizek           #+#    #+#              #
#    Updated: 2026/07/12 14:03:24 by msnizek          ###   ########.fr        #
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
    echo -e "${RED}Chyba: Spustitelný soubor $CUB3D nebyl nalezen!${NC}"
    exit 1
fi

# ---------------------------------------------------------
# 1. TESTOVÁNÍ NEVALIDNÍCH MAP
# Očekáváme, že program vyhodí chybu a sám se rychle ukončí.
# ---------------------------------------------------------
echo -e "${CYAN}=========================================${NC}"
echo -e "${CYAN}      TESTOVÁNÍ NEVALIDNÍCH MAP          ${NC}"
echo -e "${CYAN}=========================================${NC}"

for map in "$INVALID_DIR"/*.cub; do
    [ -e "$map" ] || continue 
    
    map_name=$(basename "$map")
    output=$(timeout 2 "$CUB3D" "$map" 2>&1)
    exit_code=$?

    if [ $exit_code -eq 124 ]; then
        echo -e "${RED}[KO]${NC} $map_name -> Program běží! Mapa zřejmě prošla parsováním."
    elif [ $exit_code -ne 0 ]; then
        if echo "$output" | grep -q "^Error"; then
            echo -e "${GREEN}[OK]${NC} $map_name -> Správně zamítnuto."
            # Vypíše samotnou chybovou hlášku s odsazením
            echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
        else
            echo -e "${YELLOW}[??]${NC} $map_name -> Zamítnuto, ale nezačíná na 'Error'."
            echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
        fi
    else
        echo -e "${RED}[KO]${NC} $map_name -> Ukončeno s úspěchem (Exit kód 0), to je špatně."
    fi
done

echo ""

# ---------------------------------------------------------
# 2. TESTOVÁNÍ VALIDNÍCH MAP
# Očekáváme, že se spustí herní smyčka a program zasáhne timeout.
# ---------------------------------------------------------
echo -e "${CYAN}=========================================${NC}"
echo -e "${CYAN}        TESTOVÁNÍ VALIDNÍCH MAP          ${NC}"
echo -e "${CYAN}=========================================${NC}"

for map in "$VALID_DIR"/*.cub; do
    [ -e "$map" ] || continue
    
    map_name=$(basename "$map")
    output=$(timeout 2 "$CUB3D" "$map" 2>&1)
    exit_code=$?

    if [ $exit_code -eq 124 ]; then
        echo -e "${GREEN}[OK]${NC} $map_name -> Mapa úspěšně načtena, hra běží (ukončeno timeoutem)."
    elif [ $exit_code -eq 0 ]; then
        echo -e "${YELLOW}[??]${NC} $map_name -> Okamžitě ukončeno (0). Zkontroluj, zda nepadáš před mlx_loop."
    else
        echo -e "${RED}[KO]${NC} $map_name -> Program spadl (Exit kód $exit_code)!"
        echo -e "${YELLOW}     Výpis:${NC}"
        echo -e "${GRAY}$(echo "$output" | sed 's/^/       /g')${NC}"
    fi
done

echo -e "\n${CYAN}=========================================${NC}"
echo -e "${YELLOW}               HOTOVO!                   ${NC}"
echo -e "${CYAN}=========================================${NC}"