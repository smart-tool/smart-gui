FILE *fileGUI;

void clearFile_GUI(){
	fclose(fopen("guiExtract/timeAlg.txt", "w+"));
}

void printLenght_GUI(int pattSize){
	fileGUI = fopen("guiExtract/timeAlg.txt","a+");
	fprintf(fileGUI, "%d%c", pattSize, '|');
	fclose(fileGUI);
}

void printTime_GUI(double currentTime){
	fileGUI = fopen("guiExtract/timeAlg.txt","a+");
	fprintf(fileGUI, "%.2f%c", currentTime, ',');
	fclose(fileGUI);	
}

void printOK_GUI(){
	fileGUI = fopen("guiExtract/timeAlg.txt","a+");
	fprintf(fileGUI, "%s\n", "OK");
	fclose(fileGUI);
}

void printComma_GUI(){
	fileGUI = fopen("guiExtract/timeAlg.txt","a+");
	fprintf(fileGUI, "%c", ',');
	fclose(fileGUI);
}

void printNull_GUI(){
	fileGUI = fopen("guiExtract/timeAlg.txt","a+");
	fprintf(fileGUI, "%s%c", "null", ',');
	fclose(fileGUI);
}