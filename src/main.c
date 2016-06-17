/***********************************main.c***********************************
Student Name: Aaron Gordon          Student Number: 0884023
Date: March 29th, 2015               Course Name: CIS*2500 Intermediate Programming
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
        1) I have read and understood the University policy on academic integrity;
        2) I have completed the Computing with Integrity Tutorial on Moodle; and
        3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "linkedList.h"

int main(int argc, char * argv[])
{
	FILE * file;
	char * name;
	char * group;
	char line[900][256];
	char ch;
	char type;
	char temp;
	double calories;
	double calTotal = 0;
	double vegTotal = 0, meatTotal = 0, dairyTotal = 0, grainsTotal = 0, fatTotal = 0;
	double vegTot = 0, meatTot = 0, dairyTot = 0, grainsTot = 0, fatTot = 0;
	int i;

	Food * head = (Food *)malloc(sizeof(Food));
	Food * ptr = (Food *)malloc(sizeof(Food));

	head = NULL;
	ptr = NULL;

	if (argc < 2)
	 {
		printf("No argument inputted. Exiting...\n");
		exit(0);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	 {
		printf("Error opening file. Exiting...\n");
		exit(0);
	}
	while((ch = fgetc(file)) != EOF)
	 {
		line[i][0] = ch;
		while((ch = fgetc(file)) != '\n')
		 {
			line[i][strlen(line[i])] = ch;
			if (line[i][strlen(line[i])-1] == ',' && isdigit(line[i][strlen(line[i])-2]))
			 {
				temp = fgetc(file);
			}
		}
		name = strtok(line[i], ",");
		group = strtok(NULL, ",");
		calories = atoi(strtok(NULL, ","));
		calTotal += calories;
		type = temp;
		ptr = createRecord(name, group, calories, type);
		if (head == NULL)
		 {
			head = ptr;
		}
		else if (type == 'j')
		 {
			head = addToBack(head, ptr);
		}
		else if (type == 'h')
		 {
			head = addToFront(head, ptr);
		}

		if (strcmp(group, "vegfruit") == 0)
		 {
                vegTotal += calories;
                vegTot += 1;
		}
		else if (strcmp(group, "grains") == 0)
         {
                grainsTotal += calories;
                grainsTot += 1;
        }
		else if (strcmp(group, "dairy") == 0)
         {
                dairyTotal += calories;
                dairyTot += 1;
        }
		else if (strcmp(group, "meat") == 0)
         {
                meatTotal += calories;
                meatTot += 1;
        }
		else if (strcmp(group, "fat") == 0)
         {
                fatTotal += calories;
                fatTot += 1;
        }

		i++;
	}
	printf("%d\n", (int)calTotal);
	printf("%.0f\n", vegTotal / vegTot);
	printf("%.0f\n", meatTotal / meatTot);
	printf("%.0f\n", dairyTotal / dairyTot);
	printf("%.0f\n", grainsTotal / grainsTot);
	printf("%.0f\n", fatTotal / fatTot);
	printList(head);
	destroyList(head);

	return 0;
}
