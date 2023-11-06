//Lec03
//Structure Array
#define MAX_STUDENTS 200
#define MAX_NAME 100

typedef struct {
	int month;
	int date;
}BirthdayType;

typedef struct {
	char name[MAX_NAME];
	BirthdayType birthday;
}StudentType;

StudentType students[MAX_STUDENTS];

void main(){
	strcpy(students[0].name, "HongGilDong");
    students[0].birthday.month = 10;
	students[0].birthday.date = 28;
}