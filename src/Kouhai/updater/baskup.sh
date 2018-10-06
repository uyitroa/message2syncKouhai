#!/usr/bin/env bash
function select_rows () {
  sqlite3 ~/Library/Messages/chat.db "$1"
}

msg=`select_rows "
    select is_from_me,text, datetime(date + strftime('%s', '2001-01-01 00:00:00'), 'unixepoch', 'localtime') as date from message where  ROWID=(SELECT MAX(ROWID) from message) AND handle_id=(
    select handle_id from chat_handle_join where chat_id=(
    select ROWID from chat where guid='iMessage;-;superhung220703@gmail.com')
    )"`
current_msg=`cat res/data/last.txt`
if [[ "$msg" != "$current_msg" && "$msg" == *"1|"* ]]
then
echo "$msg" > res/data/last.txt
echo "$msg" >> res/data/line.txt
exit
fi
