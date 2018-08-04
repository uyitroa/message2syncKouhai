function select_rows () {
  sqlite3 ~/Library/Messages/chat.db "$1"
}

select_rows "
    select is_from_me,text, datetime(date + strftime('%s', '2001-01-01 00:00:00'), 'unixepoch', 'localtime') as date from message where handle_id=(
    select handle_id from chat_handle_join where chat_id=(
    select ROWID from chat where guid='iMessage;-;+33762226688')
    )" | sed 's/1\|/Me: /g;s/0\|/Friend: /g' > ../res/data/line.txt
