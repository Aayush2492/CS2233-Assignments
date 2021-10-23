#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"
#include "avl_tree.h"
#include "file_reader.h"
#include "stack_by_linked_list.h"
#include "queue_by_linked_list.h"

int main()
{
    binary_search_tree* songLibrary = newBinarySearchTree();

    readFile(songLibrary);
    
    printf("Enter name of the songs you want to remove from library. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to be deleted from library !\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songLibrary->searchBST(songLibrary->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songLibrary->deleteFromBST(songLibrary, nodeFound);
                printf("%s has been removed from library\n", str);
            }
        }
    }

    avl_tree* songPlaylist = newAVLTree();
    printf("Enter name of the songs you want to add to playlist. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to add to library\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songLibrary->searchBST(songLibrary->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songPlaylist->insertIntoAVL(songPlaylist, nodeFound->song);
                printf("%s has been added to playlist\n", nodeFound->song);
            }
        }
    }

    printf("Enter name of the songs you want to remove from playlist. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to be deleted from playlist!\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songPlaylist->searchAVL(songPlaylist->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songPlaylist->deleteFromAVL(songPlaylist, nodeFound);
                printf("%s has been removed from playlist\n", str);
            }
        }
    }

    stack* recentSongsStack = newStack();
    queue* temporaryQueue = newQueue();
    tree_node* currentSongNode = songPlaylist->minimumAVL(songPlaylist->root);
    printf("Play next song, previous songs or end? n/p:k/e\n");
    while(true)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len=strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';

        if(!strcmp(str, "n"))
        {
            if(songPlaylist->root != NULL && currentSongNode != NULL)
            {
                printf("Playing %s\n", currentSongNode->song);
                recentSongsStack->push(recentSongsStack, currentSongNode->song);
                currentSongNode = songPlaylist->successorAVL(currentSongNode);
            }
            else
            {
                printf("Your playlist is empty\n");
            }
        }
        else if (str[0]=='p' && str[1]==':')
        {
            // Removing the p and : from str
            str = str + 2;

            unsigned numberOfPreviousSongs = atoi(str);
            for(int i = 1 ; i <= numberOfPreviousSongs ; i++)
            {
                if(recentSongsStack->numberOfElements==0)
                {
                    printf("There aren\'t %u previous songs\n", numberOfPreviousSongs);
                    break;
                }
                else
                {
                    char* currentSong = recentSongsStack->top(recentSongsStack);
                    printf("Playing %s\n", currentSong);
                    recentSongsStack->pop(recentSongsStack);
                    temporaryQueue->enqueue(temporaryQueue, currentSong);
                }
            }

            //Emptying the temporary queue into the recent songs stack
            unsigned initialSizeOfTempQueue = temporaryQueue->numberOfElements;
            for(int i=1 ; i<=initialSizeOfTempQueue ; i++)
            {
                recentSongsStack->push(recentSongsStack, temporaryQueue->front(temporaryQueue));
                temporaryQueue->dequeue(temporaryQueue);
            }
        }
        else if(!strcmp(str, "e"))
        {
            printf("Bye\n");
            break;
        }
        else
        {
            printf("Please enter a correct choice\n");
        }
        
    }
    return 0;
}