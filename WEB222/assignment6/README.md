# Assignment 6 Instructions

## Introduction

Please see "Assignment 6.pdf" for detailed instructions for this assignment,
including all requirements, due dates, etc.

Before following the rest of these instructions, please confirm with your
professor that you are in fact required to use this setup.

To submit your assignment, you must successfully run the "npm run prepare-submission"
build script discussed below.  Please read all of the following information
carefully, and don't skip any steps.

The following setup is meant to give you some experience working with
command-line build environments, automated testing, and validation for
web projects.

## Setup

You must first install Node.js on your computer. Please follow installation
instructions at:

https://nodejs.org/en/

You can install the LTS (long term support) version of node.js, which is
currently 10.13.0, although any version should work.

## Install Dependencies

Once you have Node.js installed, start a command line terminal, and 
navigate (i.e., "cd") to the folder/directory where these files are located. 
When you type "dir" (Windows) or "ls" (Linux/macOS) you should see this README.md
file, package.json, and the other files associated with this setup.

Install all the necessary dependencies using the npm command (installed with node):

npm install

This should download and save all the necessary files to a folder named
node_modules in the current directory.

If you have trouble getting "npm install" to work:

* Did you install node.js?
* If you type "node --version" in your terminal, does it print the version?
* Are you in the right directory (you must cd into the correct directory)

If you need help, ask your classmates or talk to your professor.

## Writing your code

All of your HTML, CSS, and JavaScript files should be placed in Assigment6/.

The build scripts discussed below all assume your files are located there.

## Using Build Scripts

There are a number of build scripts you can run to help you check, validate, and
use your files. All of the scripts are run using the following command format

"npm run script-name":

1. To start a web server so you can browse all the files in Assignment6/*:

    npm run server

    You can now open the URL printed in your console. Use CTRL+C to stop the server 

2. To properly auto-format your HTML, CSS, and JavaScript using https://prettier.io: 

    npm run prettier

    This will reformat and rewrite all the .html, .css, and .js files in Assigment6/

3. To check your JavaScript files for errors using https://eslint.org/:

    npm run eslint

    If you're not sure what an error means, look at the rule name in
    https://eslint.org/docs/rules/

4. To check your CSS files for errors using https://stylelint.io/:

    npm run stylelint

    If you're not sure what an error means, look at the rule name in
    https://stylelint.io/user-guide/rules/

5. To check your HTML for errors using http://html5.validator.nu:

    npm run validate

6. To check your HTML, CSS, and JavaScript all at once (run 3, 4, 5 together):

    npm run check

7. To create Assignment6.zip with all the files in Assignment6/*:

    npm run zip

8. To run steps 2-7 above one after another, and prepare your code for submission:

    npm run prepare-submission

## VSCode Editor and Extensions

You are encouraged to use Visual Studio Code (VSCode) as your editor

https://code.visualstudio.com/

A number of extensions are available that will work automatically with
the scripts and configuration in this project:

* stylelint https://marketplace.visualstudio.com/items?itemName=shinnn.stylelint
* eslint https://marketplace.visualstudio.com/items?itemName=dbaeumer.vscode-eslint
* prettier https://marketplace.visualstudio.com/items?itemName=esbenp.prettier-vscode

Once these are installed VSCode will automatically show you errors as you type.

## Other Files

You may be wondering about some of the other files in this project.  While you
don't need to modify them, or use them directly, here is what each one does:

.eslintrc.js - configuration for eslint, see https://eslint.org/docs/user-guide/configuring

.npmrc - configuration settings for npm, see https://docs.npmjs.com/files/npmrc

.prettierrc.js - configuration settings for prettier, see https://prettier.io/docs/en/configuration.html

.stylelintrc.js - configuration settings for stylelint, see https://stylelint.io/user-guide/configuration/

package.json - node.js package info, dependencies, build scripts, see https://docs.npmjs.com/files/package.json

package-lock.json - a generated file with dependency version information, see https://docs.npmjs.com/files/package-lock.json
