/***********************************linkedList.c***********************************
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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "linkedList.h"

Food * createRecord(char * name, char * group, double calories, char theType)
{
	Food * record = (Food * )malloc(sizeof(Food));
	record->name = malloc(sizeof(char)*50);
	record->foodGroup = malloc(sizeof(char)*50);

	strcpy(record->name, name);
	strcpy(record->foodGroup, group);
	record->calories = calories;
	record->type = theType;
	record->next = NULL;

	return record;
}

Food * addToBack(Food * theList, Food * toBeAdded)
{
	Food * current = (Food *)malloc(sizeof(Food));
   if (theList == NULL)
     {
        return toBeAdded;
    }

	current = theList;
	while(current->next != NULL)
	 {
		current = current->next;
	}
	current->next = toBeAdded;
	toBeAdded->next = NULL;

	return theList;
}

Food * addToFront(Food * theList, Food * toBeAdded)
{
	if (theList == NULL)
     {
		return toBeAdded;
    }

	toBeAdded->next = theList;

	return toBeAdded;
}

Food * removeFromFront(Food * theList)
{
	Food * current;

	current = theList->next;

	return current;
}

Food * removeFromBack(Food * theList)
{
	Food * current;
	current = theList;
	while(theList->next != NULL)
	 {
		theList = theList->next;
	}
	theList = NULL;

	return current;
}

Food * getLastItem(Food * theList)
{
	while(theList->next != NULL)
	 {
		theList = theList->next;
	}

	return theList;
}

bool isEmpty(Food * theList)
{
	if (theList == NULL)
	 {
		return true;
	}
	else
	 {
		return false;
	}
}

char * printRecord(Food * toPrint)
{
	char * record;
	char * temp = malloc(sizeof(char)*100);

	sprintf(temp, "%s (%s):%.02f[%c]", toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type);
	record = malloc(sizeof(char)*(strlen(temp)));
	strcpy(record, temp);

	return record;
}

void printList(Food * theList)
{
	while(theList->next != NULL)
	 {
		printf("%s\n", printRecord(theList));
		theList = theList->next;
	}
	printf("%s\n", printRecord(theList));
}

void destroyElement(Food * theElement)
{
	free(theElement->name);
	free(theElement->foodGroup);
}

void destroyList(Food * theList)
{
	Food * current = (Food *)malloc(sizeof(Food));
	while(theList != NULL)
	 {
		current = theList->next;
		destroyElement(theList);
		free(theList);
		theList = current;
	}
}
