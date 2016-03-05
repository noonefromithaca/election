#include <stdio.h>
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
	string30 billName;
	datetype datePassed;
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

void display(candidateType);
void getInput(candidateType *);

//extra functions for getName
int isALetter(char letter)
	{
	if (letter >= 'A' && <= 'Z')
		return 1;
	else if (letter >= 'a' && letter <= 'z')
		return 1;
	return 0;
	}

int validName(String30 tempName)
	{
	int i = 0;
	while (i < 30)
		{
		if (!(isALetter(tempName[i])))
			return 0;
		}
	return 1;
	}

/*
2. Create a function getName() that will get the name of the candidate.
*/
void getName(candidateName *name)
	{
	candidateName FullName;
	String30 tempName;
	char MiddleInitial;
	do
		{
		printf("Input first name: ");
		scanf("%s", tempName);
		if (validName(tempName))
			strcpy(FullName.FName, tempName);
		} while (!(validName(tempName)));
		do
			{
			printf("Input middle initial: ");
			scanf("%c", MiddleInitial);
			if (isALetter(MiddleInitial))
				FullName.MI = MiddleInitial;
			} while (!(isALetter(MiddleInitial))
					 do
						 printf("Input last name: ");
			scanf("%s", tempName);
			if (validName(tempName))
				strcpy(FullName.LName, tempName);
	}while (!(validName(tempName)));
}


/*
3. Create a function getDate() that will get the date information.*/
void getDate(dateType *date) //Sorry, I'm not good at getting dates
	{
	printf("Enter The Month: ");
	scanf("%d", date.Month);
	printf("Enter The Day: ");
	scanf("%d", date.Day);
	printf("Enter The Year: ");
	scanf("%d", date.Year);

	}

/*
4. Modify getInput() to now call function getName() to get the name of the candidate and call function getDate() to get the birthday.
Also update this function to include getting input for the information that is newly introduced in this exercise: bill should now
include the date the bill was passed (here you also need to call getDate()) and rating (so input for the percentage, the organization,
and the date? with the date taken as user input using the function getDate() as well).
*/

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
	string50 temp;
	getName(&(pCand->Name));
	printf("Enter birthday: \n");
	getDate(pCand.Birthday);
	printf("Enter position: ");
	scanf("%s", pCand->Position);
	scanf("%s", pCand->Party);

	pCand->nBills = 0;

	do
		{
		printf("Enter bill passed #%d: ", pCand->nBills + 1);
		/*
		fgets(Candidate.BillsPassed[Candidate.nBills], 51, stdin);
		Candidate.BillsPassed[Candidate.nBills][strlen(Candidate.BillsPassed) - 1] = '\0';
		*/

		fgets(temp, 51, stdin);
		temp[strlen(temp) - 1] = '\0';
		if (strcmp(temp, "XXX") != 0)
			{
			strcpy(pCand->BillsPassed.billName[pCand->nBills], temp);
			pCand->nBills++;
			getDate(&(pCand->BillsPassed.datePassed));
			}

		} while (pCand->nBills < MAX_BILLS && strcmp(temp, "XXX") != 0);
	}

//extra function for display date
String30 getMonth(int num)
	{
	String30 Month;
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
	return Month;
	}


/*
5. Create a function displayDate() that will display the date information in the format of <Month in word form> <day>, <year>. For example: March 3, 2016
*/

void displayDate(dateType date)
	{
	printf("%s %d, %d", getMonth(date.month), date.day, date.year);
	}

/*
6. Update function display() that will also include displaying of all information of 1 candidate, including those newly introduced in
this exercise. Whenever appropriate, call displayDate().
*/
void
display(candidateType *pCand) {
	printf("Name: %s %c. %s\n", CandidateType.Name.LName, Name.MI, Name.FName);
	printf("Birthday: %d/%d/%d\n", CandidateType.Birthday.month, Birthday.day, Birthday.year);
	printf("Position: %s"\n, CandidateType.Position);
	printf("Number of bills passed: %d\n", CandidateType.nBills);
	for (i = 0; i < nBills; i++)
		printf("Bill#%d : %s Date Implemented: %d\n", i + 1, CandidateType.billsPassed[i]);
	printf
	}

/*
7. Create a function displayByParty() that will accept as parameter the array of candidates and the string party and will display all
candidates (and their corresponding information) who belongs to the same party. This function should call function display() as part
of the solution. Allow the user to press a key (of your choice, like Enter) to display the next candidate that is of the same party.
*/
void displayByParty() {

	}

/*
8. Create a function swap() that will accept addresses of 2 candidate structures as parameter. After the function, these addresses
will contain the updated values, i.e., the data in both structures will be swapped.
*/
void swap(candidateType * pCand1, candidateType * pCand2) {
	candidateType tempCand;
	*pCand = tempCand;
	*pCand = *pCand2;
	*pCand2 = tempCandl;
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
void/*(?)*/sortByRating(arrCandidates[], numCandidates)//This is Potato's code
	{
	int i, indexG = 0;
	float greatest;
	for (i = 0; i < numCandidates; i++)
		{
		greatest = arrCandidates[indexG].survey;
		if (greatest < arrCandidates[i].survey)
			{
			swap(arrCandidates[indexG], arrCandidates[i]);
			indexG = i;
			}
		}
	}
/*
10. Create a function sortAlphabetical() that will rearrange the contents of the array of candidates based on the last name of the
candidate. This function will not perform any display (i.e., no printf()). Part of the solution to this function is to call function swap().
*/
void/*(?)*/ sort Alphabetical(arrCandidates[])
	{

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
	int opt, nCand = 0;
	arrCandidates Candidates;
	printf("Select an option: ");
	printf("0 - Add Candidate Info");
	printf("1 - Display All Candidates");
	printf("2 - Display By Rating");
	printf("3 - Display By Party");
	printf("4 - Exit");
	scanf("%d", &opt);

	switch (opt)
		{
			case 0:
				getInput(Candidates[nCand])
					break;
			case 1:
				display
					break;
			case 2:
				break;
			case 3:
				break;
			case 4:
		}

	return 0;
	}