Program is simple this time around. Simply create an input file with multiple lines denoted in the below format and
the program will take it (an argument needs to be made leading to the file in the format bin/runMe FILELOCATION.txt
after "make"ing the program with the "make" command) and print out the average vegfruit, meat, dairy, grains and
fat calories for the food items in that order (and preceeded by the total calories for all foods). Then the list in
the format specified below writes out all of the food items.

In addition, the healthy foods are listed first and are followed by the junk foods as organized by a linked list.

Input file format:
<name,foodgroup,calories,type>
	- no spaces
	- name and foodgroup are strings
	- calories is a real number (like 24.3)
	- type is a single character, either h or j for healthy or junk. Something else will not contribute to the
program its values.
	- this format may be repeated many times.

List print format:
(for every instance) Name (Food Group):calories[type]

//////////////////////LIMITATIONS\\\\\\\\\\\\\\\\\\\\\
- None known.
