function _update_ps1() {
    #export PS1="$(~/Documents/dev/prompt/main $? 2> /dev/null)"
    export PS1="$(~/Documents/dev/prompt/plompt/build/bin/plompt $?)"
    #export PS1="$(python2 ~/Documents/dev/prompt/powerline-shell/powerline-shell.py $?)"
}

export PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
