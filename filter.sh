#!/bin/bash
# 1. 处理 ==text== 为 @mark{text}
# 2. 将 **text** 转换为 <b>text</b>
# 3. 将 <!-- id:xxx --> \n # Title 转换为 # Title {#xxx}
# 4. 将 [text](../path/filename.cpp) 转换为 @ref filename.cpp "text"
# 5. 将 [text](#anchor) 转换为 @ref anchor "text"

CONTENT=$(cat "$1")
FILENAME=$(basename "$1")

# 为主要文档文件自动添加 ID
if [ "$FILENAME" == "1_基础.md" ]; then
    CONTENT="<!-- id:basics_doc -->\n$CONTENT"
elif [ "$FILENAME" == "1_智能指针概说.md" ]; then
    CONTENT="<!-- id:smart_pointer_doc -->\n$CONTENT"
fi

# 使用 perl 方便处理跨行
echo -e "$CONTENT" | perl -0777 -pe 's/==([^=]*)==/\@mark{$1}/g; s/\*\*(.*?)\*\*/<b>$1<\/b>/g; s/<!-- id:(\S+) -->\s*\n\s*(#+)\s*(.*)/$2 $3 {#$1}/g; s/\[([^\]]+)\]\(\.\.\/[^\)]+\/([^\/\)]+)\)/\@ref $2 "$1"/g; s/\[([^\]]+)\]\(#([^ \)]+)\)/\@ref $2 "$1"/g'
