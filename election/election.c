#include <stdio.h>
#include <string.h>
#define MAX_CAND  20
#define MAX_BILLS 10

typedef char string30[31];
typedef char string50[51];

typedef struct {
	int month,
		day,
		year;
} dateType;

//a.) name further consists of the first name, last name, and middle initial
/* Structure for Name */
typedef struct {
	string30 FName;
	string30 LName;
	char MI; //Note: middle initial is one letter
} nameType;

/* b.) each bill passed is not a string, but a structure that contains the bill and the date it was passed */
/* billsType */
typedef struct {
	string50 billName;
	dateType datePassed;
} billsType;

/*c.) we add another information in the candidate structure representing the rating, where the rating is further defined to
contain the percentage of confidence/possible votes from a survey, the organization who administered the survey, and the
date of the survey.*/
typedef struct {
	float survey;
	string30 surOrg;
	dateType surDate;
} surveyType;

/* candidateType *////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
	nameType Name;  //Not sure 'bout this nested structure thing. Please correct if wrong.
	dateType Birthday;
	string30 Position,
		Party;     // take note that your identifiers for the alias and field name may confuse you

	surveyType Rating;
	billsType BillsPassed[MAX_BILLS];
	int      nBills;
} candidateType;

typedef candidateType arrCandidates[MAX_CAND];


/* FUNCTIONS BELOW, TYPDEFS ABOVE *//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11111111111111111111

//extra functions for getName
int isALetter(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
		return 1;
	else if (letter >= 'a' && letter <= 'z')
		return 1;
	else if (letter == ' ')
		return 1;
	return 0;
}

int validName(string30 tempName)
{
	int i = 0, len;
	len = strlen(tempName);
	while (i < len)
	{
		if (!(isALetter(tempName[i])))
			return 0;
		i++;
	}
	return 1;
}

void
clear(void)
{
	while (getchar() != '\n');
}

/*
2. Create a function getName() that will get the name of the candidate.
*/
void getName(nameType * name)
{
	string30 tempName;
	char MiddleInitial;
	do
	{
		printf("Input first name: ");
		clear();
		fgets(tempName, 31, stdin);
		tempName[strlen(tempName) - 1] = '\0';
		if (validName(tempName))
			strcpy(name->FName, tempName);
		else
			printf("Invalid input.\n\n");
	} while (!(validName(tempName)));
	do
	{
		printf("Input middle initial: ");
		scanf(" %c", &MiddleInitial);
		if (isALetter(MiddleInitial))
			name->MI = MiddleInitial;
	} while (!(isALetter(MiddleInitial)));
	do
	{
		printf("Input last name: ");
		clear();
		fgets(tempName, 31, stdin);
		tempName[strlen(tempName) - 1] = '\0';
		if (validName(tempName))
			strcpy(name->LName, tempName);
	} while (!(validName(tempName)));
}


/*
3. Create a function getDate() that will get the date information.*/
void getDate(dateType * date) //Sorry, I'm not good at getting dates
{
	printf(" Enter The month: ");
	scanf("%d", &(date->month));
	printf(" Enter The day: ");
	scanf("%d", &(date->day));
	printf(" Enter The year: ");
	scanf("%d", &(date->year));
}

/*
4. Modify getInput() to now call function getName() to get the name of the candidate and call function getDate() to get the birthday.
Also update this function to include getting input for the information that is newly introduced in this exercise: bill should now
include the date the bill was passed (here you also need to call getDate()) and rating (so input for the percentage, the organization,
and the date? with the date taken as user input using the function getDate() as well).
*/

void getRating(surveyType * rating)
{
	printf("Enter the percentage of confidence/possible votes from a survey: ");
	scanf("%f", &(rating->survey));
	printf(" Enter the name of the organization who administered the survey: ");
	clear();
	fgets(rating->surOrg, 31, stdin);
	rating->surOrg[strlen(rating->surOrg) - 1] = '\0';
	printf(" Enter the date of the survey: \n");
	getDate(&(rating->surDate));
}

/*typedef struct {
nameType Name ;  //Not sure 'bout this nested structure thing. Please correct if wrong.
dateType Birthday;
string30 Position,
Party;     // take note that your identifiers for the alias and field name may confuse you

surveyType Rating;
billsType BillsPassed[MAX_BILLS];
int      nBills;
} candidateType;

typedef struct {
string30 billName;
datetype datePassed;
} billsType;
*/
void getInput(candidateType *pCand)
{
	string30 temp;
	getName(&(pCand->Name));
	printf("\nEnter birthday below: \n");
	getDate(&(pCand->Birthday));
	printf("Enter position: ");
	clear();
	fgets(pCand->Position, 31, stdin);
	pCand->Position[strlen(pCand->Position) - 1] = '\0';
	printf("Enter party: ");
	fgets(pCand->Party, 31, stdin);
	pCand->Party[strlen(pCand->Party) - 1] = '\0';
	getRating(&(pCand->Rating));

	pCand->nBills = 0;

	do
	{
		printf("Enter 'XXX' to end input.\n");
		printf("Enter bill passed #%d: ", pCand->nBills + 1);
		/*
		fgets(Candidate.BillsPassed[Candidate.nBills], 51, stdin);
		Candidate.BillsPassed[Candidate.nBills][strlen(Candidate.BillsPassed) - 1] = '\0';
		*/
		clear();
		fgets(temp, 51, stdin);
		temp[strlen(temp) - 1] = '\0';
		if (strcmp(temp, "XXX") != 0)
		{
			strcpy(pCand->BillsPassed[pCand->nBills].billName, temp);
			getDate(&(pCand->BillsPassed[pCand->nBills].datePassed));
			pCand->nBills++;
		}
	} while (pCand->nBills < MAX_BILLS && strcmp(temp, "XXX") != 0);
}

//extra function for display date
void getMonth(int num, string30 Month)
{
	switch (num)
	{
		case 1: strcpy(Month, "January"); break;
		case 2: strcpy(Month, "February"); break;
		case 3: strcpy(Month, "March"); break;
		case 4: strcpy(Month, "April"); break;
		case 5: strcpy(Month, "May"); break;
		case 6: strcpy(Month, "June"); break;
		case 7: strcpy(Month, "July"); break;
		case 8: strcpy(Month, "August"); break;
		case 9: strcpy(Month, "September"); break;
		case 10: strcpy(Month, "October"); break;
		case 11: strcpy(Month, "November"); break;
		case 12: strcpy(Month, "December"); break;
	}
}


/*
5. Create a function displayDate() that will display the date information in the format of <Month in word form> <day>, <year>. For example: March 3, 2016
*/
void displayDate(dateType date)
{
	string30 strMonth;
	getMonth(date.month, strMonth);
	printf("%s %d, %d", strMonth, date.day, date.year);
}

/*
6. Update function display() that will also include displaying of all information of 1 candidate, including those newly introduced in
this exercise. Whenever appropriate, call displayDate().
*/
void
display(candidateType pCand) {
	int i;
	printf("\n");
	printf("Name: %s %c. %s\n", pCand.Name.FName, pCand.Name.MI, pCand.Name.LName);
	printf("Birthday: ");
	displayDate(pCand.Birthday);
	printf("\nPosition: %s\n", pCand.Position);
	printf("Party: %s\n", pCand.Party);
	printf("Rating: %.2f\n", pCand.Rating.survey);
	printf("Date of survey: ");
	displayDate(pCand.Rating.surDate);
	printf("\nOrganization that held the survey: %s\n", pCand.Rating.surOrg);
	printf("Number of bills passed: %d\n", pCand.nBills);
	for (i = 0; i < pCand.nBills; i++)
	{
		printf("Bill #%d : %s\n Date implemented: ", i + 1, pCand.BillsPassed[i].billName);
		displayDate(pCand.BillsPassed[i].datePassed);
		printf("\n");
	}
	printf("\n");

	//printf (printf what?)
}

/*
7. Create a function displayByParty() that will accept as parameter the array of candidates and the string party and will display all
candidates (and their corresponding information) who belongs to the same party. This function should call function display() as part
of the solution. Allow the user to press a key (of your choice, like Enter) to display the next candidate that is of the same party.
*/
void displayByParty(arrCandidates Candidates, string30 party, int nCand) {
	int i;
	if (strcmp(party, "Independent") == 0)
		printf("Independent candidates: \n");
	else
		printf("Candidates from the %s Party: \n", party);
	for (i = 0; i < nCand; i++)
		if (strcmp(Candidates[i].Party, party) == 0)
		{
			display(Candidates[i]);
			printf("\n");
		}
}

/*
8. Create a function swap() that will accept addresses of 2 candidate structures as parameter. After the function, these addresses
will contain the updated values, i.e., the data in both structures will be swapped.
*/
void swap(candidateType * pCand1, candidateType * pCand2) {
	candidateType tempCand;
	tempCand = *pCand1;
	*pCand1 = *pCand2;
	*pCand2 = tempCand;
}

/*
typedef struct {
string30 FName;
string30 LName;
char MI; //Note: middle initial is one letter
} nameType;
*/

/*
9. Create a function sortByRating() that will rearrange the contents of the array of candidates from the one with the highest rating
to the lowest rating. This function will not perform any display (i.e., no printf()). Part of the solution to this function is to call
function swap(). Hint: You may use the algorithm to sort an array of floating point values that we discussed before.
*/
void sortByRating(arrCandidates Candidates, int numCandidates)//This is Potato's code
{
	int i, indexG = 0;
	float greatest;
	for (i = 0; i < numCandidates; i++)
	{
		greatest = Candidates[indexG].Rating.survey;
		if (greatest < Candidates[i].Rating.survey)
		{
			swap(&Candidates[indexG], &Candidates[i]);
			indexG = i;
		}
	}
}

/*
10. Create a function sortAlphabetical() that will rearrange the contents of the array of candidates based on the last name of the
candidate. This function will not perform any display (i.e., no printf()). Part of the solution to this function is to call function swap().
*/
void sortAlphabetical(arrCandidates Candidates, int numCandidates)
{
	int i, indexG = 0;
	char greatest;
	for (i = 0; i < numCandidates; i++)
	{
		greatest = Candidates[indexG].Name.LName[0];
		if (Candidates[indexG].Name.LName[0] >= 'a' && Candidates[indexG].Name.LName[0] <= 'z')
			greatest = greatest - 32;
		if (Candidates[i].Name.LName[0] >= 'a' && Candidates[i].Name.LName[0] <= 'z')
		{
			if (greatest > Candidates[i].Name.LName[0] - 32)
			{
				swap(&Candidates[indexG], &Candidates[i]);
				indexG = i;
			}
		} else
			if (greatest > Candidates[i].Name.LName[0])
			{
				swap(&Candidates[indexG], &Candidates[i]);
				indexG = i;
			}
	}
}

/*
11. Update the main program such that the user is allowed to navigate through a series of menu options until he chooses to exit.
The menu options are:
a . Add Candidate Info : This option will ask 1 candidate information from the user.
b. Display All Candidates : This option will display all candidates (and their respective information) in alphabetical order.
Thus, in this option, the function sortAlphabetical() should be called. The function display() should also be called as part of the
solution. Note that the user is to be asked to press a key (of your choice, like N or Enter) before the information of the next
candidate may be shown.
c. Display By Rating: In this option, the function sortByRating() should first be called. After which, part of the solution
should call function display(). The user is also asked to press a key before the next candidate information will be displayed.
d. Display By Party: Here, the user is asked to input the party to search for. Then, the function displayByParty() is called.
e. Exit : If this option is chosen, the program then terminates properly. Remember that exit() should not be called.
*/
int main()
{
	int opt, nCand = 0, i;
	arrCandidates Candidates;
	string30 strInput;
	do
	{
		printf("\n\nSelect an option: \n");
		printf("0 - Add Candidate Info\n");
		printf("1 - Display All Candidates\n");
		printf("2 - Display By Rating\n");
		printf("3 - Display By Party\n");
		printf("4 - Exit\n");
		scanf("%d", &opt);

		switch (opt)
		{
			case 0:
				getInput(&Candidates[nCand]);
				nCand++;
				break;
			case 1:
				sortAlphabetical(Candidates, nCand);
				for (i = 0; i < nCand; i++)
					display(Candidates[i]);
				break;
			case 2:
				sortByRating(Candidates, nCand);
				for (i = 0; i < nCand; i++)
					display(Candidates[i]);
				break;
			case 3:
				printf("Enter the name of the party: \n");
				clear();
				fgets(strInput, 51, stdin);
				strInput[strlen(strInput) - 1] = '\0';
				displayByParty(Candidates, strInput, nCand);
				break;
			case 4:
				break;
		}

	} while (opt != 4);

	return 0;
}
