#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rss.h"

Rss * createEmptyRss() {
  return createRss("", "", "", "");
}

Rss * createRss(const char * title, const char * link, const char * date, const char * description) {

  Rss *rss = (Rss *)malloc(sizeof(Rss) * 1);

  rss->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(rss->title, title);

  rss->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(rss->link, link);

  rss->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(rss->date, date);

  rss->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(rss->description, description);

  return rss;
}

void initRss(Rss *feed, const char* title, const char* link, const char* date, const char* description) {

  feed->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(feed->title, title);

  feed->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(feed->link, link);

  feed->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(feed->date, date);

  feed->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(feed->description, description);

  return;
}

char *rssToString(const Rss *item) {
  if(item == NULL) {
    char *result = (char *)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }

  int n = strlen(item->title) + strlen(item->link) + strlen(item->date) + strlen(item->description) + 22;

  char *str = (char *)malloc(sizeof(char) * n);

  sprintf(str, "Title: %s\nURL: %s\nDate: %s\n\t%s", item->title, item->link, item->date, item->description);

  return str;
}

void printRss(const Rss * item) {
  char *str = rssToString(item);
  printf("%s\n",str);
  free(str);
  return;
}
