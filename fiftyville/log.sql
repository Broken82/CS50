-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM  crime_scene_reports;
| 295 | 2021 | 7     | 28  | Humphrey Street      | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
| 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

SELECT * FROM bakery_security_logs WHERE day = '28' and hour = 10 and minute > 15 and activity = 'exit';

id  | year | month | day | hour | minute | activity | license_plate
 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55

SELECT * FROM people where license_plate = '322W7JE' OR license_plate = '0NTHK55';

 id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55


SELECT * FROM atm_transactions WHERE year = '2021' and month = '7' and day = '28' and atm_location = 'Leggett Street' and transaction_type = 'withdraw';

+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
SELECT * FROM people where license_plate in (SELECT license_plate FROM bakery_security_logs WHERE hour = '10' AND month = '7' and day = '28' and minute > 20);

 id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 396669 | Iman   | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 652412 | Denise | (994) 555-3373 | 4001449165      | NRYN856       |
| 660982 | Thomas | (286) 555-0131 | 6034823042      | WD5M8I6       |
| 748674 | Jeremy | (194) 555-5027 | 1207566299      | V47T75I       |
+--------+--------+----------------+-----------------+---------------+

SELECT * FROM bank_accounts WHERE account_number in (SELECT account_number FROM atm_transactions WHERE year = '2021' and month = '7' and day = '28' and atm_location = 'Leggett Street');

+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 49610011       | 686048    | 2010          |
| 86363979       | 948985    | 2010          |
| 26013199       | 514354    | 2012          |
| 16153065       | 458378    | 2012          |
| 28296815       | 395717    | 2014          |
| 25506511       | 396669    | 2014          |
| 28500762       | 467400    | 2014          |
| 76054385       | 449774    | 2015          |
| 81061156       | 438727    | 2018          |
+----------------+-----------+---------------+

SELECT * FROM people WHERE id in (SELECT person_id FROM bank_accounts WHERE account_number in (SELECT account_number FROM atm_transactions WHERE year = '2021' and month = '7' and day = '28' and atm_location = 'Leggett Street'));
#it selects people name that withrawed money from atm
+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
| 948985 | Kaelyn  | (098) 555-1164 | 8304650265      | I449449       |
+--------+---------+----------------+-----------------+---------------+

It narrows our search to Iman, Diana, Taylor

SELECT * FROM phone_calls WHERE caller = '(829) 555-5269' or caller = '(770) 555-1861' or caller = '(286) 555-6063' and day = '28';

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 137 | (770) 555-1861 | (770) 555-1196 | 2021 | 7     | 26  | 163      |
| 198 | (770) 555-1861 | (680) 555-4935 | 2021 | 7     | 27  | 430      |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 284 | (286) 555-6063 | (310) 555-8568 | 2021 | 7     | 28  | 235      |
| 345 | (829) 555-5269 | (286) 555-0131 | 2021 | 7     | 29  | 337      |
| 401 | (770) 555-1861 | (123) 555-5144 | 2021 | 7     | 30  | 491      |
| 442 | (829) 555-5269 | (022) 555-4052 | 2021 | 7     | 30  | 232      |
| 465 | (829) 555-5269 | (367) 555-0409 | 2021 | 7     | 31  | 412      |
+-----+----------------+----------------+------+-------+-----+----------+

It narrows it down to Diana and Taylor

SELECT * FROM airports WHERE city = 'Fiftyville';

+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+

SELECT * FROM flights WHERE origin_airport_id = '8' and day = '29';

+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+

SELECT * FROM airports WHERE id = '4';

+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+

so they escaped to NYC

SELECT * FROM people WHERE phone_number = '(725) 555-3243' or phone_number = '(676) 555-6554';

+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 250277 | James  | (676) 555-6554 | 2438825627      | Q13SVG6       |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       |
+--------+--------+----------------+-----------------+---------------+

accomplices

SELECT * FROM passengers WHERE flight_id = '36';

+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 1540955065      | 5C   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
+-----------+-----------------+------+

So it was TAYLOR, id 1988161715





