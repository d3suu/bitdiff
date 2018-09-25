# bitdiff
Shows difference between files on bit-level

## Build
bitdiff uses custom bash script for building, and development help. <br /><br />
To build bitdiff binary file, simply copy-paste these commands in project directory:<br />
`chmod +x build.sh` <br />
`./build.sh`

## Development
bitdiff uses custom bash script for building, and development help. <br /><br />
To check for TODO's, type:<br />
`./build.sh todo`<br /><br />
To check for WIP's, type:<br />
`./build.sh wip`<br /><br />
To check for WARNING's in code, type:<br />
`./build.sh warning`<br /><br />
To check for everything at once, type:<br />
`./build.sh a`<br /><br />

## Use
`./bitdiff -a <file_1> -b <file_2>`
<br />
 - -a is for first file to compare<br />
 - -b is for second file to compare<br />

