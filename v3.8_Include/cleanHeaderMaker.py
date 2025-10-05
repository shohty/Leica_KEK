import re

# ファイル読み込み
with open('v3.8_Include/ES_C_API_Def_clean_tmp.h', 'r') as f:
    content = f.read()

# /* */ コメントを削除（複数行対応）
content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
# // コメントを削除
content = re.sub(r'//.*', '', content)

# ファイル書き込み
with open('v3.8_Include/ES_C_API_Def_clean_nocomment.h', 'w') as f:
    f.write(content)

print("Deleting comments in C++ format is completed!!")
