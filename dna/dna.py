import csv
import sys


def main():

    people = []
    first_line = []
    if len(sys.argv) != 3:
        print("Invalid usage.")

    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for pipo in reader:
            first_line = list(pipo)
            break
        for pipo in reader:
            people.append(pipo)


    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as f:
        dna = f.read()


    # TODO: Find longest match of each STR in DNA sequence
    dna_dict = {}
    for i in first_line:
        if i == 'name':
            continue
        dna_dict[i] = longest_match(dna, i)
        dna_dict[i] = str(dna_dict[i])

    dna_dict = list(dna_dict.values())




    
    # TODO: Check database for matching profiles
    for i in range(len(people)):
        checking = 0
        for j in range(len(dna_dict)):
            if people[i][j+1] == dna_dict[j]:
                checking += 1
            if checking == len(first_line) - 1:
                print(people[i][0])
                return

    print("No match")
    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
