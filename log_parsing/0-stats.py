#!/usr/bin/python3
"""
This script reads input lines from a log file and calculates accumulated
statistics on file sizes and HTTP status codes.
"""
import sys
import signal


class LogParser:
    def __init__(self):
        self.total_size = 0
        self.status_codes_count = {
            200: 0,
            301: 0,
            400: 0,
            401: 0,
            403: 0,
            404: 0,
            405: 0,
            500: 0
        }
        self.line_count = 0

    def print_stats(self):
        """ Function that prints accumulated statistics. """
        print(f"File size: {self.total_size}")
        for code in sorted(self.status_codes_count):
            if self.status_codes_count[code] > 0:
                print(f"{code}: {self.status_codes_count[code]}")

    def signal_handler(self, sig, frame):
        """ Function that handles keyboard interrupt CTRL+C. """
        self.print_stats()
        sys.exit(0)

    def process_line(self, line):
        """ Process a single line of log. """
        parts = line.split()
        if len(parts) < 7:
            return
        try:
            file_size = int(parts[-1])
            status_code = parts[-2]
            # We validate that the status code is numeric
            if status_code.isdigit():
                status_code = int(status_code)
                if status_code in self.status_codes_count:
                    self.status_codes_count[status_code] += 1
            # We update the total size regardless of the status code
            self.total_size += file_size
            self.line_count += 1
        except (ValueError, IndexError):
            # Log the error for debugging
            print(f"Error processing line: {line.strip()}", file=sys.stderr)

    def run(self):
        """ Main method to run the log parser. """
        signal.signal(signal.SIGINT, self.signal_handler)
        for line in sys.stdin:
            self.process_line(line)
            if self.line_count % 10 == 0:  # Print stats every 100 lines
                self.print_stats()
        self.print_stats()  # Print final stats at end


if __name__ == "__main__":
    parser = LogParser()
    parser.run()
