/*
 * SMART: string matching algorithms research tool.
 * Copyright (C) 2012  Simone Faro and Thierry Lecroq
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * 
 * contact the authors at: faro@dmi.unict.it, thierry.lecroq@univ-rouen.fr
 * download the tool at: http://www.dmi.unict.it/~faro/smart/
 */

int outputPHP(double TIME[NumAlgo][NumPatt], double BEST[NumAlgo][NumPatt], double WORST[NumAlgo][NumPatt], double STD[NumAlgo][NumPatt], 
			  int alpha, char *filename, char *expcode, int dif, int std) {
  	int  i, il, algo;
   	FILE *fp;
	char outname[100];
   	//printing results in txt format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	//mkdir(outname,S_IROTH);
	strcat(outname, "/");
	strcat(outname, filename);
	strcat(outname, ".php");
   	printf("\tSaving data on %s/%s.php\n",expcode,filename);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/%s.txt\n",expcode,filename);
		return 0;
	}
	fprintf(fp,"<?\n$%s = array(\n",filename);
	fprintf(fp,"\t\"PATT\" => array(",expcode,filename);
	for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
		fprintf(fp,"\"%d\", ", PATT_SIZE[il]);
	}
	fprintf(fp, "),\n");
   	for(algo=0; algo<NumAlgo; algo++) {
		if(EXECUTE[algo]) {
   			fprintf(fp,"\t\"%s\" => array(",str2upper(ALGO_NAME[algo]));
   			for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
   				if(TIME[algo][il]==0)  fprintf(fp,"\"VOID\", ");
   	  	 		else
					fprintf(fp,"\"%.2f\", ",TIME[algo][il]);
   			}
   			fprintf(fp,"),\n");
			if(dif) {
				fprintf(fp,"\t\"%s.best\" => array(",str2upper(ALGO_NAME[algo]));
				for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
					if(TIME[algo][il]==0)  fprintf(fp,"\"0.1\", ");
					else
						fprintf(fp,"\"%.2f\", ",BEST[algo][il]);
				}
				fprintf(fp,"),\n");
				fprintf(fp,"\t\"%s.worst\" => array(",str2upper(ALGO_NAME[algo]));
				for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
					if(TIME[algo][il]==0)  fprintf(fp,"\"0.1\", ");
					else
						fprintf(fp,"\"%.2f\", ",WORST[algo][il]);
				}
				fprintf(fp,"),\n");
			}
			if(std) {
				fprintf(fp,"\t\"%s.std\" => array(",str2upper(ALGO_NAME[algo]));
				for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
					if(TIME[algo][il]==0)  fprintf(fp,"\"VOID\", ");
					else
						fprintf(fp,"\"%.2f\", ",STD[algo][il]);
				}
				fprintf(fp,"),\n");
			}
		}
   	}
	fprintf(fp,");\n?>");
   	fclose(fp);
	
	
	return 1;
}


int outputTXT(double TIME[NumAlgo][NumPatt], int alpha, char *filename, char *expcode) {
  	int  i, il, algo;
   	FILE *fp;
	char outname[100];
   	//printing results in txt format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	//mkdir(outname,S_IROTH);
	strcat(outname, "/");
	strcat(outname, filename);
	strcat(outname, ".txt");
   	printf("\tSaving data on %s/%s.txt\n",expcode,filename);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/%s.txt\n",expcode,filename);
		return 0;
	}
   	for(algo=0; algo<NumAlgo; algo++) {
		if(EXECUTE[algo]) {
			int first = 1;
   			fprintf(fp,"%s",str2upper(ALGO_NAME[algo]));
			for(i=0; i<20-strlen(ALGO_NAME[algo]); i++) fprintf(fp," ");
   			for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
				if(!first) fprintf(fp,"\t");
				first = 0;
   				if(TIME[algo][il]==0)  fprintf(fp,"-");
   	  	 		else
   	 	  		fprintf(fp,"%.2f",TIME[algo][il]);
   			}
   			fprintf(fp,"\n");
		}
   	}
   	fclose(fp);


	return 1;
}

int outputLatex(double TIME[NumAlgo][NumPatt], int alpha, char *filename, char *expcode) {
  	int  i, j,il, algo;
   	FILE *fp;
	char outname[100];
   	//printing results in latex format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	//mkdir(outname,S_IROTH);
	strcat(outname, "/");
	strcat(outname, filename);
	strcat(outname, ".tex");
   	printf("\tSaving data on %s/%s.tex\n",expcode,filename);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/%s.txt\n",expcode,filename);
		return 0;
	}
	int start=0;
	while(PATT_SIZE[start]<MINLEN) start++;
	int end=start;
	while(PATT_SIZE[end]<=MAXLEN) end++;
	fprintf(fp,"\\begin{tabular}{|l|");
	for(j=start; j<end; j++) fprintf(fp,"l");
	fprintf(fp,"|}\n\\hline\n");
	fprintf(fp,"$m$");
	for(j=start; j<end; j++) fprintf(fp," & $%d$",PATT_SIZE[j]);
	fprintf(fp,"\\\\\n");
   	for(algo=0; algo<NumAlgo; algo++) {
		if(EXECUTE[algo]) {
			int first = 1;
   			fprintf(fp,"\\textsc{%s}",str2upper(ALGO_NAME[algo]));
   			for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
   				if(TIME[algo][il]==0)  fprintf(fp," & -");
   	  	 		else
   	 	  		fprintf(fp," & %.2f",TIME[algo][il]);
   			}
   			fprintf(fp,"\\\\\n");
		}
   	}
	fprintf(fp,"\\hline\n\\end{tabular}");
   	fclose(fp);
	return 1;
}

int outputXML(double TIME[NumAlgo][NumPatt], int alpha, char *filename, char *expcode) {
  	int  i, il, algo;
   	FILE *fp;
	char outname[100];
	//finds the best result for each pattern length
	double BEST[NumPatt];
	for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
		double best = 999999.0;	
		for(algo=0; algo<NumAlgo; algo++) if(EXECUTE[algo] && TIME[algo][il]<best && TIME[algo][il]>0.1) best=TIME[algo][il];
		BEST[il] = best;
	}
   	//printing results in xml format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	mkdir(outname,S_IROTH);
	strcat(outname, "/");
	strcat(outname, filename);
	strcat(outname, ".xml");
   	printf("\tSaving data on %s/%s.xml\n",expcode,filename);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/%s.xml\n",expcode,filename);
		return 0;
	}
	fprintf(fp,"<RESULTS>\n\t<CODE>%s</CODE>\n\t<TEXT>%s</TEXT>\n",expcode,filename);
   	for(algo=0; algo<NumAlgo; algo++) {
		if(EXECUTE[algo]) {
   			fprintf(fp,"\t<ALGO>\n\t\t<NAME>%s</NAME>\n",str2upper(ALGO_NAME[algo]));
			for(i=0; i<20-strlen(ALGO_NAME[algo]); i++) fprintf(fp," ");
   			for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
   				if(TIME[algo][il]==0)  fprintf(fp,"\t\t<DATA>-</DATA>\n");
   	 	  		fprintf(fp,"\t\t<DATA>%.2f</DATA>\n",TIME[algo][il]);
   			}
   			fprintf(fp,"\t</ALGO>\n");
		}
   	}
	fprintf(fp,"\t<BEST>\n");
	for(il=0; il<NumPatt; il++)	if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN) {
  		fprintf(fp,"\t\t<DATA>%.2f</DATA>\n",BEST[il]);
	}
	fprintf(fp,"\t</BEST>\n");
	fprintf(fp,"</RESULTS>");
   	fclose(fp);
	return 1;
}

int outputHTML(double TIME[NumAlgo][NumPatt], int alpha, char *filename, char *expcode) {
  	int  i, il, algo;
   	FILE *fp;
	char outname[100];
   	//printing results in html format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	mkdir(outname,S_IROTH);
	strcat(outname, "/");
	strcat(outname, filename);
	strcat(outname, ".html");
   	printf("\tSaving data on %s/%s.html\n",expcode,filename);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/%s.html\n",expcode,filename);
		return 0;
	}
	fprintf(fp,"<html>\n\
		<head>\n\
		\t<title>SMART: experimental results %s on %s</title>\n\
		\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n\
		\t<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />\n\
		</head>\n\
		<body>\n\
		\t<script type=\"text/javascript\">\n\
		\t\tif (window.XMLHttpRequest) {\n\
		\t\t\t// code for IE7+, Firefox, Chrome, Opera, Safari\n\
	  	\t\t\txmlhttp=new XMLHttpRequest();\n\
		\t\t}\n\
		\t\telse {\n\
		\t\t\t// code for IE6, IE5\n\
  		\t\t\txmlhttp=new ActiveXObject(\"Microsoft.XMLHTTP\");\n\
		\t\t}\n\
		\t\txmlhttp.open(\"GET\",\"%s.xml\",false);\n\
		\t\txmlhttp.send();\n\
		\t\txmlDoc=xmlhttp.responseXML; \n\
		\t\tdocument.write(\"<h2>SMART: experimental results %s on %s</h2><br>\");\n\
		\t\tdocument.write(\"<table align=\\\"center\\\">\");\n",expcode,filename,filename,expcode,filename);
	fprintf(fp,"document.write(\"<tr><td></td>\");\n");
	for(i=0; PATT_SIZE[i]>0; i++) if(PATT_SIZE[i]>=MINLEN && PATT_SIZE[i]<=MAXLEN)
		fprintf(fp,"document.write(\"<td><b>%d</b></td>\");\n",PATT_SIZE[i]);
	fprintf(fp,"document.write(\"</tr>\");\n");
	fprintf(fp,"\
		\t\tvar best=xmlDoc.getElementsByTagName(\"BEST\");\n\
		\t\tvar bestvalues = best[0].getElementsByTagName(\"DATA\");\n\
		\t\tvar x=xmlDoc.getElementsByTagName(\"ALGO\");\n\
		\t\tfor (i=0;i<x.length;i++) { \n\
		\t\t\tdocument.write(\"<tr><td><b>\");\n\
  		\t\t\tdocument.write(x[i].getElementsByTagName(\"NAME\")[0].childNodes[0].nodeValue);\n\
  		\t\t\tdocument.write(\"</b></td>\");\n\
		\t\t\tvar y = x[i].getElementsByTagName(\"DATA\");\n\
		\t\t\tfor (j=0;j<y.length;j++) { \n\
  		\t\t\t\tdocument.write(\"<td>\");\n\
		\t\t\t\tif(y[j].childNodes[0].nodeValue==bestvalues[j].childNodes[0].nodeValue) document.write(\"<b><u>\");\n\
  		\t\t\t\tif(y[j].childNodes[0].nodeValue<0.05) document.write(\"--\");\n\
  		\t\t\t\telse document.write(y[j].childNodes[0].nodeValue);\n\
		\t\t\t\tif(y[j].childNodes[0].nodeValue==bestvalues[j].childNodes[0].nodeValue) document.write(\"</u></b>\");\n\
  		\t\t\t\tdocument.write(\"</td>\");\n\
		\t\t\t}\n\
  		\t\t\tdocument.write(\"</tr>\");\n\
		\t\t}\n\
		\t\tdocument.write(\"</table>\");\n\
		\t</script>\n\
		</body>\n\
		</html>");
   	fclose(fp);
	return 1;
}

int outputINDEX(char *filename, char *expcode) {
  	int  i, sett,il, algo;
   	FILE *fp;
	char outname[100];
   	//printing results in html format
	strcpy(outname, "results/");
	strcat(outname, expcode);
	mkdir(outname,S_IROTH);
	strcat(outname, "/index.html");
   	printf("\tWriting %s/index.html\n",expcode);
   	if ( !(fp = fopen(outname,"w") ) ) {
		printf("\tError in writing file %s/index.html\n",expcode);
		return 0;
	}
	fprintf(fp,"<html>\n\
		\t<head>\n\
		\t\t<title>SMART: experimental results %s</title>\n\
		\t\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n\
		\t\t<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />\n\
		\t</head>\n\
		\t<body>\n\
		\t\t<h2>SMART: experimental results %s</h2><br>\n\
		\t\t<table align=\"center\">\n",expcode,expcode);
	if( strcmp(filename,"all") ) fprintf(fp,"\t\t\t<tr><td><a href=\"%s.html\">Experimental results on %s</a></td></tr>\n",filename,filename);
	else
		for(sett=0; sett<NumSetting; sett++) {
			fprintf(fp,"\t\t\t<tr><td><a href=\"%s.html\">Experimental results on %s</a></td></tr>\n",SETTING_BUFFER[sett],SETTING_BUFFER[sett]);
	}
	fprintf(fp,"\t\t</table>\n\
		\t</body>\n\
		</html>");
   	printf("\n");
   	fclose(fp);
	return 1;
}


