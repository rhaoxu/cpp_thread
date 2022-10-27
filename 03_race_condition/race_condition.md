

#### race condition

|               thread 1                |               thread 2                |
| :-----------------------------------: | :-----------------------------------: |
|      load balance_ into register      |                                       |
|                                       |      load balance_ into register      |
|     increasement register’s value     |                                       |
|                                       |     increasement register’s value     |
| update balance_ with register’s value |                                       |
|                                       | update balance_ with register’s value |





> different registers got increasemented and balance_ was overwritten
>
> we suppose to get 2, but sometimes we got 1



