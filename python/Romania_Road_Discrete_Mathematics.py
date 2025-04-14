graph = {'oradea': {'zerind': 71, 'sibiu': 151, },
         'zerind': {'arad': 75, 'oradea': 71},
         'sibiu': {'arad': 140, 'oradea': 151, 'rimnicu vilcea': 80, 'fagaras': 99},
         'arad': {'zerind': 75, 'sibiu': 140, 'timisoara': 118},
         'timisoara': {'arad': 118, 'lugoj': 111},
         'lugoj': {'timisoara': 111, 'mehadia': 75},
         'mehadia': {'dobreta': 70, 'lugoj': 70},
         'dobreta': {'craiova': 120, 'mehadia': 75},
         'craiova': {'pitesti': 138, 'rimnicu vilcea': 146, 'dobreta': 120},
         'rimnicu vilcea': {'sibiu': 80, 'pitesti': 97, 'craiova': 146},
         'fagaras': {'bucharest': 211, 'sibiu': 99},
         'pitesti': {'rimnicu vilcea': 97, 'craiova': 138, 'bucharest': 101},
         'bucharest': {'pitesti': 101, 'fagaras': 211, 'urziceni': 85, 'giurgiu': 90},
         'giurgiu': {'bucharest': 90},
         'urziceni': {'bucharest': 85, 'hirsova': 98, 'vaslui': 142},
         'hirsova': {'urziceni': 98, 'eforie': 86},
         'vaslui': {'urziceni': 142, 'lasi': 92},
         'lasi': {'neamt': 87, 'vaslui': 92},
         'neamt': {'lasi': 87},
         'eforie': {'hirsova': 86},

         }


def graph_function(graph, start_city, end_city):
    global min_distance_city
    short_road = {}
    roads = {}
    citys = graph
    number = 99999999
    path = []

    for city in citys:
        short_road[city] = number
    short_road[start_city] = 0

    while citys:
        min_distance_city = None

        for city in citys:
            if min_distance_city is None:
                min_distance_city = city

            elif short_road[city] < short_road[min_distance_city]:
                min_distance_city = city

        citys_path = graph[min_distance_city].items()

        for city, weight in citys_path:

            if weight + short_road[min_distance_city] < short_road[city]:
                short_road[city] = weight + short_road[min_distance_city]
                roads[city] = min_distance_city

        citys.pop(min_distance_city)

    citys = end_city

    while citys != start_city:

        try:
            path.insert(0, citys)
            citys = roads[citys]
        except KeyError:
            print('Path not reachable')
            break
    path.insert(0, start_city)

    if short_road[end_city] != number:
        new = " --> ".join(path)
        print(f"And the path is :  {new}")
        print(f"The shortest road length from {start_city} to {end_city} is : {str(short_road[end_city])} KM")


start = input("Enter starting city :")
end = input("Enter Destination City  : ")
end.lower()
start.lower()
graph_function(graph, start, end)
