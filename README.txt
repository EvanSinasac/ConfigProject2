INFO6025 Configuration & Deployment (Project 2)
Evan Sinasac - 1081418

I mainly built and compiled using Visual Studios 2019 in Debug and 64 bit, I added the include paths for Release in 64 bit, and for Debug and Release in 32 bit.  So it should work in any combination, but I focused testing and writing in Debug 64.

Simple project following the instructions.  I decided to use rapidJSON because it looked a little bit friendlier and easier to figure out.  I got some help from a Uni friend because I knew that they worked with JSON a bit before, and they basically explained it as, "After parsing the document, everything is basically in a big array and you access it by their names."  Which isn't much advice, but that simple explanation made it something that I was not fully understanding to realizing that it was actually pretty simple lol.  Now writing to files with rapidJSON, probably going to need some help with that (since I have a feeling there has to be a better way then re-writing the entire file every time).  

I forwent the harder marks and focused on rapidJSON.  The main runs a read on the config file, then loads the user's preferred language, then begins a loop where it presents the user's preferences, prompts for an input, and allows the user to change their preferences.  Went with the ones in the project document, Display Name, favorite number, favorite animal (from a list), and preferred language.

The Config Reader Writer reads the config file, stores a struct of the User's preferences, and writes to the preference file when a change is made.

The Language Reader loads and stores the messages in the inputted language file, and has getters that return the strings stored from the messages.

Console control is pretty straightforward, follow the on-screen instructions, and enter 'x' at any point to exit the program.