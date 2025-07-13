How to start using git from terminal?

4 Location stages where our code lives in git.
- /localWorkingDirectory : This is where your actually code and store code locally.
- Staging area : This is where changes are hold before commiting.
- local Repository : This is where we store commited changes locally.
- Remote Repository : Server like git hub for sharing and backing up code.


Step 1 : First create a repository in you github profile.
Step 2 : Then in a git clone <repo_url> to the desired location.

Step 3 : Open your loacal working directory. Make Some changes in files or folders.

	*For Starter create a practise and create a file using vim pratice.c 

Step 4 : Now use git add . to add the snap shot of those file into the staging area.

Step 5 : Use git commit to add the snap shot of the staging area and add it to your local Repository.

	This will create some logs of the permanent changes which we can refer back.

Step 6 : To share your code with your team. We use git push to the Remote repository.
	
	cmd : git push origin main 	//For creating a branch main.
 
	But before pushing your code into the remote repository. 
	First git pull the changes which are done by your team.
	Then git merge to reflect those changes into your local working directory.
	


