package TicketBooking;

/**
 * Thrown when a booking operation cannot be completed.
 * Checked exception — callers are forced to handle booking failures explicitly.
 */
 class BookingException extends Exception {

     BookingException(String message) {
        super(message);
    }

     BookingException(String message, Throwable cause) {
        super(message, cause);
    }
}

