#include "../include/Quiries.h"

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	if (argc == 0) {
		printf("No information is found");
	}

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void InsertIntoFilm(sqlite3* db) {
	const char* sql =
		"insert into film (name, director, year, country, cost, income, profit, ticket, genre, cinematheatre_id)\n"
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	char name[30], director[30], country[30], genre[30];
	int year, cost, income, profit, ticket, cinematheatre_id;
	printf("\n%s", "Enter name: ");
	scanf("%s", name);
	printf("\n%s", "Enter director: ");
	scanf("%s", director);
	printf("\n%s", "Enter year: ");
	scanf("%d", &year);
	printf("\n%s", "Enter country: ");
	scanf("%s", country);
	printf("\n%s", "Enter cost: ");
	scanf("%d", &cost);
	printf("\n%s", "Enter income: ");
	scanf("%d", &income);
	printf("\n%s", "Enter profit: ");
	scanf("%d", &profit);
	printf("\n%s", "Enter ticket: ");
	scanf("%d", &ticket);
	printf("\n%s", "Enter genre: ");
	scanf("%s", genre);
	printf("\n%s", "Enter cinematheatre id: ");
	scanf("%d", &cinematheatre_id);

	if (rc == SQLITE_OK) {
		sqlite3_bind_text(res, 1, name, -1, 0);
		sqlite3_bind_text(res, 2, director, -1, 0);
		sqlite3_bind_int(res, 3, year);
		sqlite3_bind_text(res, 4, country, -1, 0);
		sqlite3_bind_int(res, 5, cost);
		sqlite3_bind_int(res, 6, income);
		sqlite3_bind_int(res, 7, profit);
		sqlite3_bind_int(res, 8, ticket);
		sqlite3_bind_text(res, 9, genre, -1, 0);
		sqlite3_bind_int(res, 10, cinematheatre_id);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}
	sqlite3_step(res);
	sqlite3_finalize(res);
}

void InsertIntoCinema(sqlite3* db) {
	const char* sql =
		"insert into cinematheatres (ct_name, ct_city)\n"
		"values(?, ?);";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	char ct_name[30], ct_city[30];
	printf("\n%s", "Enter name: ");
	scanf("%s", ct_name);
	printf("\n%s", "Enter city: ");
	scanf("%s", ct_city);

	if (rc == SQLITE_OK) {
		sqlite3_bind_text(res, 1, ct_name, -1, 0);
		sqlite3_bind_text(res, 2, ct_city, -1, 0);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}
	sqlite3_step(res);
	sqlite3_finalize(res);
}

void DeleteFromFilm(sqlite3* db, int id) {
	const char* sql = "delete from film where id = ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(res, 1, id);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}
	sqlite3_step(res);
	sqlite3_finalize(res);
}

void DeleteFromCinema(sqlite3* db, int id) {
	const char* sql = "delete from cinematheatres where id = ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(res, 1, id);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}
	sqlite3_step(res);
	sqlite3_finalize(res);
}

void SelectFilmId(sqlite3* db, int id) {
	char* sql =
		"Select * from film R\n"
		"where id like ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(res, 1, id);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if (step != SQLITE_ROW) {
		printf(" No films found\n");
	}

	while (step == SQLITE_ROW) {
		for (int i = 0; i < sqlite3_column_count(res); ++i) {
			printf("%s = %s\n", sqlite3_column_name(res, i), sqlite3_column_text(res, i));
		}
		printf("\n");
		step = sqlite3_step(res);
	}

	sqlite3_finalize(res);
}

void SelectCinemaId(sqlite3* db, int id) {
	char* sql =
		"Select * from cinematheatres R\n"
		"where id like ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(res, 1, id);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if (step != SQLITE_ROW) {
		printf(" No cinemas found\n");
	}

	while (step == SQLITE_ROW) {
		for (int i = 0; i < sqlite3_column_count(res); ++i) {
			printf("%s = %s\n", sqlite3_column_name(res, i), sqlite3_column_text(res, i));
		}
		printf("\n");
		step = sqlite3_step(res);
	}

	sqlite3_finalize(res);
}

void SelectCinemaName(sqlite3* db, const char* name) {
	char* sql =
		"Select * from cinematheatres R\n"
		"where ct_name like ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_text(res, 1, name, -1, 0);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if (step != SQLITE_ROW) {
		printf(" No cinemas found\n");
	}

	while (step == SQLITE_ROW) {
		for (int i = 0; i < sqlite3_column_count(res); ++i) {
			printf("%s = %s\n", sqlite3_column_name(res, i), sqlite3_column_text(res, i));
		}
		printf("\n");
		step = sqlite3_step(res);
	}

	sqlite3_finalize(res);
}

void SelectFilmName(sqlite3* db, const char* name) {
	char* sql =
		"Select * from film R\n"
		"where name like ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_text(res, 1, name, -1, 0);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if (step != SQLITE_ROW) {
		printf(" No films found\n");
	}

	while (step == SQLITE_ROW) {
		for (int i = 0; i < sqlite3_column_count(res); ++i) {
			printf("%s = %s\n", sqlite3_column_name(res, i), sqlite3_column_text(res, i));
		}
		printf("\n");
		step = sqlite3_step(res);
	}

	sqlite3_finalize(res);
}

void SelectFilmDirector(sqlite3* db, const char* director) {
	char* sql =
		"Select * from film R\n"
		"where director like ?;";
	sqlite3_stmt* res;
	int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_text(res, 1, director, -1, 0);
	}
	else {
		fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if (step != SQLITE_ROW) {
		printf(" This director dont have any films\n");
	}

	while (step == SQLITE_ROW) {
		for (int i = 0; i < sqlite3_column_count(res); ++i) {
			printf("%s = %s\n", sqlite3_column_name(res, i), sqlite3_column_text(res, i));
		}
		printf("\n");
		step = sqlite3_step(res);
	}

	sqlite3_finalize(res);
}
void SelectAll(sqlite3* db) {
	const char* sql =
		"BEGIN TRANSACTION;"
		"SELECT * "
		"from film F "
		"inner join Cinematheatres C on C.id = F.cinematheatre_id;";
		"COMMIT;";

	char* zErrMsg = 0;
	const char* data = "Callback function called";

	int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
}

void SelectImage(sqlite3* db, int id) {
	FILE* fp = fopen("../img/result.jpg", "wb");

	if (fp == NULL) {

		fprintf(stderr, "Cannot open image file\n");

		return;
	}

	char* sql = "SELECT Data FROM Images WHERE ct_id = ?";

	sqlite3_stmt* pStmt;
	int rc = sqlite3_prepare_v2(db, sql, -1, &pStmt, 0);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(pStmt, 1, id);
	}
	else {
		fprintf(stderr, "Failed to prepare statement\n");
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

		sqlite3_close(db);

		return;
	}

	rc = sqlite3_step(pStmt);

	int bytes = 0;

	if (rc == SQLITE_ROW) {

		bytes = sqlite3_column_bytes(pStmt, 0);
	}

	fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, fp);

	if (ferror(fp)) {

		fprintf(stderr, "fwrite() failed\n");

		return;
	}

	int r = fclose(fp);

	if (r == EOF) {
		fprintf(stderr, "Cannot close file handler\n");
	}

	rc = sqlite3_finalize(pStmt);
}

void InsertImage(sqlite3* db, int id, const char* fileName) {
	FILE* fp = fopen(fileName, "rb");

	if (fp == NULL) {

		fprintf(stderr, "Cannot open image file\n");

		return;
	}

	fseek(fp, 0, SEEK_END);

	if (ferror(fp)) {

		fprintf(stderr, "fseek() failed\n");
		int r = fclose(fp);

		if (r == EOF) {
			fprintf(stderr, "Cannot close file handler\n");
		}

		return;
	}

	int flen = ftell(fp);

	if (flen == -1) {

		perror("error occurred");
		int r = fclose(fp);

		if (r == EOF) {
			fprintf(stderr, "Cannot close file handler\n");
		}

		return;
	}

	fseek(fp, 0, SEEK_SET);

	if (ferror(fp)) {

		fprintf(stderr, "fseek() failed\n");
		int r = fclose(fp);

		if (r == EOF) {
			fprintf(stderr, "Cannot close file handler\n");
		}

		return;
	}

	char data[flen + 1];

	int size = fread(data, 1, flen, fp);

	if (ferror(fp)) {

		fprintf(stderr, "fread() failed\n");
		int r = fclose(fp);

		if (r == EOF) {
			fprintf(stderr, "Cannot close file handler\n");
		}

		return;
	}

	int r = fclose(fp);

	if (r == EOF) {
		fprintf(stderr, "Cannot close file handler\n");
	}

	sqlite3_stmt* pStmt;

	char* sql = "INSERT INTO Images(Data, ct_id) VALUES(?,?)";

	int rc = sqlite3_prepare(db, sql, -1, &pStmt, 0);

	if (rc != SQLITE_OK) {

		fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));

		return;
	}

	sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);

	sqlite3_bind_int(pStmt, 2, id);

	rc = sqlite3_step(pStmt);

	if (rc != SQLITE_DONE) {

		printf("execution failed: %s", sqlite3_errmsg(db));
	}

	sqlite3_finalize(pStmt);
}