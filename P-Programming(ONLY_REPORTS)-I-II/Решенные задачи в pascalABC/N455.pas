program N455;
var
n,m:integer; //числа для решения задачи
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл


procedure input(var n:integer; var m:integer); //ввод чисел
begin
  write('Введите N: ');
  readln(n);
  write('Введите M: ');
  readln(m);
end;

function nod(n,m:integer):integer; //рекурсивная функция наибольшлего делителя
begin
if n<>0 then nod:= nod(m mod n,n) else nod:=m;
end;

begin
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Read(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin
    
    input(n,m); //ввод чисел
    writeln('Больший общий делитель: ',nod(n,m)); //вывод результата
    writeln(Yourfile,'Больший общий делитель: ',nod(n,m));
    writeln(YourFile);
    Writeln('Хотите использовать программу еще раз? Y\N'); 
    Read(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    If question = 'N' then Logic:= True; //если выключатель выключен
  
  end;
  closefile(YourFile); //закрываем файл
end.
