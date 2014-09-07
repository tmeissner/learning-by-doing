# python 3 oop - chapter 3 case study
# simple real estate application


class Property:

    def __init__(self, square_feet='', beds='', baths='', **kwargs):
        super().__init__(**kwargs)
        self.square_feet = square_feet
        self.num_bedrooms = beds
        self.num_baths = baths

    def display(self):
        print("PROPERTY DETAILS")
        print("================")
        print("square footage: {}".format(self.square_feet))
        print("bedrooms: {}".format(self.num_bedrooms))
        print("bathrooms: {}".format(self.num_baths))
        print()

    @staticmethod  # decorator form of the staticmethod constructor function
    def prompt_init():
        return dict(square_feet=input("Enter the square feet: "),
                    beds=input("Enter number of bedrooms: "),
                    baths=input("Enter number of baths: "))


class Apartment(Property):

    # class variables
    valid_laundries = ("coin", "ensuite", "none")
    valid_balconies = ("yes", "no", "solarium")

    def __init__(self, balcony = "", laundry = "", **kwargs):
        super().__init__(**kwargs)
        self.balcony = balcony
        self.laundry = laundry

    def display(self):
        super().display()
        print("APARTMENT DETAILS")
        print("laundry: %s" % self.laundry)
        print("has balcony: %s" % self.balcony)

    @staticmethod
    def prompt_init():
        parent_init = Property.prompt_init()
        laundry = get_valid_input("What laundry facilities does the property"
            "have?", Apartment.valid_laundries)
        balcony = get_valid_input("Does the property have a balcony?",
            Apartment.valid_balconies)
        parent_init.update({
            "laundry" : laundry,
            "balcony" : balcony
        })
        return parent_init


class House(Property):

    # class variables
    valid_garage = ("attached", "detached", "none")
    valid_fenced = ("yes", "no")

    def __init__(self, num_stories = "", garage = "", fenced = "", **kwargs):
        super().__init__(**kwargs)
        self.garage = garage
        self.fenced = fenced
        self.num_stories = num_stories

    def display(self):
        super().display()
        print("HOSE DETAILS")
        print ("# of stories: {}".format(self.num_stories))
        print ("garage: {}".format(self.garage))
        print ("fenced yard: {}".format(self.fenced))

    @staticmethod
    def prompt_init():
        parent_init = Property.prompt_init()
        fenced = get_valid_input("Is the yard fenced?", House.valid_fenced)
        garage = get_valid_input("Is there a garage?", House.valid_garage)
        num_stories = input("How many stories? ")
        parent_init.update({
            "fenced" : fenced,
            "garage" : garage,
            "num_stories" : num_stories
        })
        return parent_init



def get_valid_input(input_string, valid_options):
    input_string += " ({}) ".format(", ".join(valid_options))
    response = ""
    while response.lower() not in valid_options:
        response = input(input_string)
    return response
