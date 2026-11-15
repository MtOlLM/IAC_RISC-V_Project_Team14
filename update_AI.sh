rm -f AI_usage.txt

git log --all --grep="\bAI\b" --regexp-ignore-case --pretty=format:"%an | %cd%n%B" --date=format:"%d-%m-%Y %H:%M:%S" > AI_usage.txt