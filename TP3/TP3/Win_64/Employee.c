
Employee* employee_new()
{
    Employee* nuevo=(Employee*)malloc(sizeof(Employee));
    if(nuevo!=NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre," ");
        nuevo->horasTrabajadas=0;
        nuevo->sueldo=0;
    }
     return nuevo;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

}

