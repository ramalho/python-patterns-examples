import os

verbose = True

def delete_file(path):
    if verbose:
        print("deleting file '{}".format(path))
    os.remove(path)

def main():
    orig_name = 'file1'
    df=delete_file

    commands = []
    commands.append(df)

    for c in commands:
        try:
            c.execute()
        except AttributeError as e:
            df(orig_name)

    for c in reversed(commands):
        try:
            c.undo()
        except AttributeError as e:
            pass

if __name__ == "__main__":
    main()
