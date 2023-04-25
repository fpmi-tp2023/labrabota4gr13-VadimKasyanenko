#include "../include/Quiries.h"

int main(int argc, char* argv[]) {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("../lab4.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}

	int choice;
	do {
		char name[30];
		char searchPart[1];
		char path[30];
		int id = 0;
		strcpy(searchPart, "%");
		strcpy(path, "../img/");
		printf("%s\n", "Choose option:");
		printf("%s\n", "0.To exit");
		printf("%s\n", "1.Insert into films");
		printf("%s\n", "2.Insert into cinematheatres");
		printf("%s\n", "3.Delete from films");
		printf("%s\n", "4.Delete from cinematheatres");
		printf("%s\n", "5.Selsect film id");
		printf("%s\n", "6.Select cinema id");
		printf("%s\n", "7.Select film name");
		printf("%s\n", "8.Select cinema name");
		printf("%s\n", "9.Select film name part");
		printf("%s\n", "10.Select cinema name part");
		printf("%s\n", "11.Selct film director");
		printf("%s\n", "12.Show all tables");
		printf("%s\n", "13.Select picture");
		printf("%s\n", "14.Insert picture");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			InsertIntoFilm(db);
			break;
		case 2:
			InsertIntoCinema(db);
			break;
		case 3:
			printf("\n%s", "Enter id: ");
			scanf("%d", &id);
			DeleteFromFilm(db, id);
			break;
		case 4:
			printf("\n%s", "Enter id: ");
			scanf("%d", &id);
			DeleteFromCinema(db, id);
			break;
		case 5:
			printf("\n%s", "Enter id: ");
			scanf("%d", &id);
			SelectFilmId(db, id);
			break;
		case 6:
			printf("\n%s", "Enter id: ");
			scanf("%d", &id);
			SelectCinemaId(db, id);
			break;
		case 7:
			printf("\n%s", "Enter name: ");
			scanf("%s", name);
			SelectFilmName(db, name);
			break;
		case 8:
			printf("\n%s", "Enter name: ");
			scanf("%s", name);
			SelectCinemaName(db, name);
			break;
		case 9:
			printf("\n%s", "Enter name: ");
			scanf("%s", name);
			strcat(name, searchPart);
			SelectFilmName(db, name);
			break;
		case 10:
			printf("\n%s", "Enter name: ");
			scanf("%s", name);
			strcat(name, searchPart);
			SelectCinemaName(db, name);
			break;
		case 11:
			printf("\n%s", "Enter director: ");
			scanf("%s", name);
			SelectFilmDirector(db, name);
			break;
		case 12:
			SelectAll(db);
			break;
		case 13:
			printf("\n%s", "Enter id: ");
			scanf("%d", &id);
			SelectImage(db, id);
			break;
		case 14:
			printf("\n%s", "Enter cinematheatre id: ");
			scanf("%d", &id);
			printf("\n%s", "Enter file name: ");
			scanf("%s", name);
			strcat(path, name);
			printf("\n%s", path);
			InsertImage(db, id, path);
			break;
		default:
			break;
		}
	} while (choice!=0);

	sqlite3_close(db);
	return 0;
}