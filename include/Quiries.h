#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"	

static int callback(void* NotUsed, int argc, char** argv, char** azColName);

void InsertIntoFilm(sqlite3* db);

void InsertIntoCinema(sqlite3* db);

void DeleteFromFilm(sqlite3* db, int id);

void DeleteFromCinema(sqlite3* db, int id);

void SelectFilmId(sqlite3* db, int id);

void SelectCinemaId(sqlite3* db, int id);

void SelectCinemaName(sqlite3* db, const char* name);

void SelectFilmName(sqlite3* db, const char* name);

void SelectFilmDirector(sqlite3* db, const char* director);

void SelectAll(sqlite3* db);

void SelectImage(sqlite3* db, int id);

void InsertImage(sqlite3* db, int id, const char* fileName);