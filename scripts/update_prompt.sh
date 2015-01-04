#!/usr/bin/bash

function _update_ps1() {
    export PS1="$(plompt $?)"
}

export PROMPT_COMMAND="_update_ps1;"

