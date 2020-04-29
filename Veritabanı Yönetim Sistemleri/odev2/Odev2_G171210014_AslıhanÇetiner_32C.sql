CREATE TABLE "POSTSTATUS"(
	"Name" VARCHAR ( 2044 ),
	"CreationDate" DATE,
	"Count" LONG,
	"POSTSTATUS_id" ULONG,
	PRIMARY KEY( "POSTSTATUS_id" ) );
	
	
CREATE TABLE "POST"(
	"CreationDate" DATE,
	"DeletionDate" DATE,
	"Score" LONG,
	"ViewCount" LONG,
	"ownerDİsplay" PICTURE ( 512 ),
	"Tittle" VARCHAR ( 2044 ),
	"Tag" VARCHAR ( 2044 ),
	"AnswerCount" LONG,
	"CommentCount" LONG,
	"FavouriteCount" LONG,
	"ClosedDate" DATE,
	"FieldName" VARCHAR ( 2044 ),
	"POST_id" ULONG,
	"POSTTYPES_id" ULONG,
	"USER_id" ULONG,
	PRIMARY KEY( "POST_id" ) );
-- -------------------------------------------------------------

-- CREATE INDEX "index_POSTTYPES_id" ---------------------------
CREATE INDEX "index_POSTTYPES_id" ON "POST"( "POSTTYPES_id" );
-- -------------------------------------------------------------

-- CREATE INDEX "index_USER_id" --------------------------------
CREATE INDEX "index_USER_id" ON "POST"( "USER_id" );
-- -------------------------------------------------------------

CREATE TABLE "TAGS"(
	"TagName" VARCHAR ( 2044 ),
	"Count" LONG,
	"TAGS_id" ULONG,
	PRIMARY KEY( "TAGS_id" ) );
	
	CREATE TABLE "POSTTYPES"(
	"Name" VARCHAR ( 2044 ),
	"POSTTYPES_id" ULONG,
	PRIMARY KEY( "POSTTYPES_id" ) );
	
	-- CREATE TABLE "VOTE" -----------------------------------------
CREATE TABLE "VOTE"(
	"VOTETYPE_id" ULONG,
	"POST_id" ULONG,
	"USER_id" ULONG );
-- -------------------------------------------------------------

-- CREATE INDEX "index_VOTETYPE_id" ----------------------------
CREATE INDEX "index_VOTETYPE_id" ON "VOTE"( "VOTETYPE_id" );
-- -------------------------------------------------------------

-- CREATE INDEX "index_POST_id" --------------------------------
CREATE INDEX "index_POST_id" ON "VOTE"( "POST_id" );
-- -------------------------------------------------------------

-- CREATE INDEX "index_USER_id1" -------------------------------
CREATE INDEX "index_USER_id1" ON "VOTE"( "USER_id" );
-- -------------------------------------------------------------

-- CREATE TABLE "VOTETYPE" -------------------------------------
CREATE TABLE "VOTETYPE"(
	"Name" VARCHAR ( 2044 ),
	"VOTETYPE_id" ULONG,
	PRIMARY KEY( "VOTETYPE_id" ) );
-- -------------------------------------------------------------
-- CREATE TABLE "USER" -----------------------------------------
CREATE TABLE "USER"(
	"Reputation" LONG,
	"Creation" DATE,
	"Display" PICTURE ( 512 ),
	"LastAccesDate" DATE,
	"WebSiteURL" VARCHAR ( 2044 ),
	"Location" VARCHAR ( 2044 ),
	"AboutMe" VARCHAR ( 2044 ),
	"Views" LONG,
	"UpVotes" LONG,
	"DownVotes" LONG,
	"email" VARCHAR ( 2044 ),
	"USER_id" ULONG,
	PRIMARY KEY( "USER_id" ) );
-- -------------------------------------------------------------

-- CREATE TABLE "BADGETS" --------------------------------------
CREATE TABLE "BADGETS"(
	"Name" VARCHAR ( 2044 ),
	"Date" VARCHAR ( 2044 ),
	"Class" VARCHAR ( 2044 ),
	"TagBased" VARCHAR ( 2044 ),
	"USER_id" ULONG );
-- -------------------------------------------------------------
-- CREATE TABLE "COMMENT" --------------------------------------
CREATE TABLE "COMMENT"(
	"Score" LONG,
	"Text" VARCHAR ( 2044 ),
	"CreationDate" DATE,
	"USER_id" ULONG,
	"POST_id" ULONG );
-- -------------------------------------------------------------

-- CREATE INDEX "index_USER_id2" -------------------------------
CREATE INDEX "index_USER_id2" ON "COMMENT"( "USER_id" );
-- -------------------------------------------------------------

-- CREATE INDEX "index_POST_id1" -------------------------------
CREATE INDEX "index_POST_id1" ON "COMMENT"( "POST_id" );
-- -------------------------------------------------------------

-- CREATE TABLE "POSTSTATUSTYPE" -------------------------------
CREATE TABLE "POSTSTATUSTYPE"(
	"POSTSTATUS_id" ULONG,
	"POST_id" ULONG );
-- -------------------------------------------------------------
-- CREATE TABLE "POSTTAGS" -------------------------------------
CREATE TABLE "POSTTAGS"(
	"TAGS_id" ULONG,
	"POST_id" ULONG );
-- -------------------------------------------------------------
CREATE TABLE "NEWUSER"(
    NEWUSER_id ULONG,
	PRIMARY KEY( "NEWUSER_id" ) );
	
	CREATE TABLE "VOTERS"(
    VOTERS_id ULONG,
	PRIMARY KEY( "VOTERS_id" ) );
	
	CREATE TABLE "EDITORS"(
    EDITORS_id ULONG,
	PRIMARY KEY( "EDITORS_id" ) );
	
	CREATE TABLE "MODERATOR"(
    MODERATOR_id ULONG,
	PRIMARY KEY( "MODERATOR_id" ) );


INSERT INTO VOTETYPE VALUES ('LIKE',1);
INSERT INTO VOTETYPE VALUES ('DISLIKE',2);

INSERT INTO POSTTAGS VALUES ('1',1);
INSERT INTO POSTTAGS VALUES ('5',2);

INSERT INTO POST VALUES ('06.10.2018','16.09.2019',10,69,NULL,'C++',NULL,9,0,NULL,'06.10.2018',NULL,4,7,1);
INSERT INTO POST VALUES ('12.10.2019','12.10.2019',8,9,NULL,'SQL',NULL,8,10,0,'07.10.2018',NULL,55,5,89);

INSERT INTO POSTSTATUSTYPE VALUES ('1',1);
INSERT INTO POSTSTATUSTYPE VALUES ('55',2);

INSERT INTO POSTSTATUS VALUES ('CLOSED','06.10.2018',5,69);
INSERT INTO POSTSTATUS VALUES ('OPEN','16.02.2019',9,9);

INSERT INTO VOTE VALUES (5,1,6);
INSERT INTO VOTE VALUES (15,61,96);

INSERT INTO BADGETS VALUES ('GOLD','21.05.2019',NULL,NULL,59);
INSERT INTO BADGETS VALUES ('SILVER','11.08.2019',NULL,NULL,559);

INSERT INTO TAGS VALUES ('C++',51,99);

INSERT INTO POSTTYPES VALUES ('ANSWER',177);
INSERT INTO POSTTYPES VALUES ('ANSWER',187);


INSERT INTO "USER" VALUES (NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
INSERT INTO "USER" VALUES (NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,11);




