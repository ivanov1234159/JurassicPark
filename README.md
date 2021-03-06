# Проект 8: Джурасик парк
Може да видите *документацията* на кода, генерирана от **DoxyGen** [тук](https://ivanov1234159.github.io/JurassicPark/html/index.html)

**Автор:** Веселин Иванов

## Описанире на проекта

Ванката беше изключително впечатлен от последната лекция в историческия музей 
и има нова хрумка - ще става палеонтолог! Не, още по-добре, ще си отвори ферма за динозаври!
Въпреки безумните убеждения на майка си, Ванката вече има план как ще изглежда 
новият домашен зоопарк за праисторически влечуги:
динозаврите могат да са няколко вида:

- месоядни
- тревопасни
- водни
- летящи

от книгите знае, че те не съжителстват заедно, затова трябва да са разделени

необходимо е да има достатъчно храна за всички

необходимо е да има достатъчно персонал в парка, за да се грижат за всички.

*Вашата основна задача е да наподобите модела на успешен развъдник на динозаври.*

Всеки **динозавър** се характеризира чрез:

- име
- пол
- ера
    * Триас
    * Креда
    * Юра
- разред
    * тревопасен
    * месояде
    * летящ
    * воден
- вид
    * плезиозавър
    * бронтозавър
    * тиранозавър 
    * и т.н.
- храна
    * трева
    * месо
    * риба

Те са разпределени в клетки, като заедно могат да съжителстват единствено животни 
от една ера и един разред (но не задължително от един вид). 

Важна информация за **клетката** е:

- размер
    * малка (за 1 животно)
    * средна (до 3 животни)
    * голема (до 10 животни)
- климат
    * сухоземен
    * въздушен
    * воден 
    * и т.н.
- животни, които я обитават
- ера на животните вътре (ако има такива)

В нашия зоопарк отначало има произволно количество клетки и без никакви животни. 
Ново животно може да се приеме, ако има подходяща клетка за него с празно място в нея. 
Ако няма, то такава може да бъде построена, посочвайки съответния климат и размер. 

### Напишете система за управление на зоопарк, която може да:

- приема ново животно

```
add <name> <gender> <era> <type> <species> <food>
```

- строи нова клетка

```
create <climate> <size>
```

- премахва вече налично животно

```
remove <name>
```

- зарежда склада с храна

```
supply <food_name> <amount>
```

- нахранва всички животни

```
feed
```

- наема нов персонал

```
hire <count>
```

- запазва сегашното състояние на програмата

```
save
```

- показва сегашното състояние на програмата

```
status
```

- показва информация за възможностите на приграмата

```
help
```

- затваряне на приграмата

```
exit [ <save> = Yes ]
```

## Забележки:
- Може ли в началото клетките за динозаврите да са наистина случайно генерирани и като брой, и като вид?
- Не искаме при затваряне на програмата информацията да се губи. 
- Летящите динозаври са в по-голямата си част хищни :)

## 

## Външни източници

- [doctest](https://github.com/onqtam/doctest) - за тестването на проекта (програмата)