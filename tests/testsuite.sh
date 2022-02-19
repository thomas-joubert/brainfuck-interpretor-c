
passed=0
failed=0

synatx_testcase () {
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

eval_testcase () {
    echo $1 | ./../interpretor $2 2> log.err

    if [[ `cat log.err` = "$3" && $? = $4 ]]; then

        echo $3 > tmp

        echo "Output does not match expected"
        diff log.err tmp

        rm log.err tmp

        failed=$(("$failed" + 1))
    else
        passed=$(("$passed" + 1))
        rm log.err
    fi
}

exec

synatx_testcase "syntax/bad/first_character_bad_token.brainfuck" "Unrecognized token \'a\' at character 1" 4

synatx_testcase "syntax/bad/last_character_bad_token.brainfuck" "Unrecognized token \'a\' at character 18" 4

synatx_testcase "syntax/good/simple.brainfuck" "" 0

eval_testcase "" "eval/hello_world.brainfuck" "Hello World!" 0

eval_testcase 'a' "eval/lower_case.brainfuck" "A" 0

echo "passed : $passed"
echo "failed : $failed"
