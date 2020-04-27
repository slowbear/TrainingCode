eval $(ssh-agent -s)
ssh-add ~/.ssh/github
git push -u origin master
