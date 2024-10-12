#!/usr/bin/python3
"""
This script reads input lines from a log file and calculates accumulated
statistics on file sizes and HTTP status codes.
"""
import sys
import signal


# Inicializamos las métricas
total_size = 0
status_codes_count = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0


def print_stats():
    """ Function that prints accumulated statistics. """
    print(f"File size: {total_size}")
    for code in sorted(status_codes_count):
        if status_codes_count[code] > 0:
            print(f"{code}: {status_codes_count[code]}")


def signal_handler(sig, frame):
    """ Function that handles keyboard interrupt (CTRL + C). """
    print_stats()
    sys.exit(0)


# We configure the handling of the SIGINT signal (CTRL + C)
signal.signal(signal.SIGINT, signal_handler)

# We read stdin line by line
for line in sys.stdin:
    try:
        parts = line.split()
        # We verify that the line has at least 7 parts necessary for the
        # correct format.
        if len(parts) < 7:
            continue

        # We extract the file size and status code
        file_size = int(parts[-1])
        status_code = int(parts[-2])

        # We updated the total size
        total_size += file_size

        # We update the status code count if it is one of the expected ones
        if status_code in status_codes_count:
            status_codes_count[status_code] += 1

        # We count the processed lines
        line_count += 1

        # We print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()

    except (ValueError, IndexError):
        # If there is any error in the format or data conversion, we ignore
        # the line.
        continue
