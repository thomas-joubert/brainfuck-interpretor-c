
passed=0
failed=0

testcase () {
    ./../interpretor $1 2> log.err

    if [[ `cat log.err` = "$2" && $? = $3 ]]; then

        echo "first_character_bad_token : BAD, diff is :"
        echo "Unrecognized token \'a\' at character 1" > tmp

        diff log.err tmp

        rm log.err tmp

        failed=$(("$failed" + 1))
    else
        passed=$(("$passed" + 1))
        rm log.err
    fi
}

testcase "syntax/bad/first_character_bad_token.brainfuck" "Unrecognized token \'a\' at character 1" 4

testcase "syntax/bad/last_character_bad_token.brainfuck" "Unrecognized token \'a\' at character 18" 4

testcase "syntax/good/simple.brainfuck" "" 0

echo "passed : $passed"
echo "failed : $failed"
