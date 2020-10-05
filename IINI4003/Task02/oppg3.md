```c
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}
```

første ting som kan gå galt er at noen skriver inn en streng som er lengre enn 5 tegn, siden det bare er satt av plass til 5 får man segmentfeil.