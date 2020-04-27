eval $(ssh-agent -s)
ssh-add ~/.ssh/github
hub sync
