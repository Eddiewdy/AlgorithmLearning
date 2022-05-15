git add .
echo -e "\x1B[1;36m add a commit message \x1B[0m"
read msg
git commit -m "$msg"
git push -u origin master


