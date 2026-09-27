-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28;

SELECT transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_scurity_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2025
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minutes >= 15
AND bakery_security_logs.minutes <= 25;

SELECT people.name, atm_transactions.transaction_type FROM peopele
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_trasactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactiond.day 28
AND atm_location = "Leggett Steet"
AND atm transactions.transaction_type = 'withdraw';

ALTER TABLE phone_calls
ADD caller_name text;

ALTER TABLE phone_calls
ADD receiver_name text;

UPDATE phone_calls
SET caller_name = people.name
FROM people WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people WHERE phone_calls.receiver = people.phone_number;

SELECT caller, receiver FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration < 60;


UPDATE flights
SET origin_airpot_id = airpots.city
FROM airpots
WHERE flights.origin_airpots_id = airpots.id;

UPDATE flights
SET destination_airpot_id = airpots.city
FROM airpots
WHERE flights.destination_airpot_id = airpots.id;

SELECT * FROM flight
WHERE year = 2025 AND month = 7 AND day = 28
ORDER BY hour ASC
LIMIT 1;

SELECT flights.destination_airpot_id, name, phone_number, license_plate FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights_id = 36
ORDER BY flights.hour ASC;

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE (flights.year = 2025 AND flights.month = 7 AND flights.day = 28 AND flights.id = 36)

AND name IN (SELECT phone_calls.caller_name FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration < 60)

AND name IN(SELECT people.name FROM people
JOIN bakery_scurity_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2025
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minutes >= 15
AND bakery_security_logs.minutes <= 25);

AND name IN (SELECT people.name, atm_transactions.transaction_type FROM peopele
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_trasactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactiond.day 28
AND atm_location = "Leggett Steet"
AND atm transactions.transaction_type = 'withdraw');
