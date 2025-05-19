#!/bin/bash

# === CONFIGURATION ===
MY_SHELL="./42sh"
REF_SHELL="tcsh"
TEST_FILE="tests/testcases.txt"

mkdir -p logs
rm logs/*
cp 42sh tests/

# === COULEURS ===
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

echo "== DÉMARRAGE DES TESTS =="

total=0
success=0

while IFS= read -r CMD || [[ -n "$CMD" ]]; do
    total=$((total + 1))
    echo -e "\nTest $total: '$CMD'"

    rm -f out_my.txt err_my.txt out_ref.txt err_ref.txt
    touch out_my.txt err_my.txt out_ref.txt err_ref.txt

    echo "$CMD" | $MY_SHELL > out_my.txt 2> err_my.txt
    RET_MY=$?

    echo "$CMD" | $REF_SHELL > out_ref.txt 2> err_ref.txt
    RET_REF=$?

    diff -u out_ref.txt out_my.txt > logs/diff_out_$total.txt
    diff -u err_ref.txt err_my.txt > logs/diff_err_$total.txt

    if [ $RET_MY -eq $RET_REF ] && diff -q out_ref.txt out_my.txt >/dev/null && diff -q err_ref.txt err_my.txt >/dev/null; then
        echo -e "${GREEN}[OK]$NC"
        success=$((success + 1))
        rm -f logs/diff_out_$total.txt logs/diff_err_$total.txt
        rm -f out_my.txt err_my.txt out_ref.txt err_ref.txt
    else
        echo -e "${RED}[FAIL]$NC"
        echo "Commande: $CMD" > logs/fail_$total.txt
        echo "Diff STDOUT:" >> logs/fail_$total.txt
        cat logs/diff_out_$total.txt >> logs/fail_$total.txt
        echo -e "\nDiff STDERR:" >> logs/fail_$total.txt
        cat logs/diff_err_$total.txt >> logs/fail_$total.txt
        echo -e "\nCode retour ref: $RET_REF / shell: $RET_MY" >> logs/fail_$total.txt
    fi

done < "$TEST_FILE"

rm -f out_my.txt err_my.txt out_ref.txt err_ref.txt
rm -f tests/$MY_SHELL

# === RÉSUMÉ ===
echo -e "\nTests réussis: $success/$total"

if [ $success -eq $total ]; then
    echo -e "${GREEN}Tous les tests sont passés.${NC}"
    rmdir logs
else
    echo -e "${RED}Des tests ont échoué. Voir les logs dans ./logs${NC}"
fi
