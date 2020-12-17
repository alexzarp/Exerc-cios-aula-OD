void swap(Contact *x, Contact *y){ 
    Contact *temp = (Contact* ) malloc(sizeof (Contact));
    snprintf(temp->name, sizeof(temp->name), "%s", x->name);
    temp->birth.day = x->birth.day;
    temp->birth.month = x->birth.month;
    temp->birth.year = x->birth.year;
    snprintf(temp->email, sizeof(temp->email), "%s", x->email);
    snprintf(temp->phone, sizeof(temp->phone), "%s", x->phone);

    snprintf(x->name, sizeof(x->name), "%s", y->name);
    x->birth.day = y->birth.day;
    x->birth.month = y->birth.month;
    x->birth.year = y->birth.year;
    snprintf(x->email, sizeof(x->email), "%s", y->email);
    snprintf(x->phone, sizeof(x->phone), "%s", y->phone);

    snprintf(y->name, sizeof(y->name), "%s", temp->name);
    y->birth.day = temp->birth.day;
    y->birth.month = temp->birth.month;
    y->birth.year = temp->birth.year;
    snprintf(y->email, sizeof(y->email), "%s", temp->email);
    snprintf(y->phone, sizeof(y->phone), "%s", temp->phone);

    free(temp);
}